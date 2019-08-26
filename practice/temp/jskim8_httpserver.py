import time
import datetime
import BaseHTTPServer
from single_test import Neurogenie
import base64
import shutil
import json
import cv2
from collections import OrderedDict

HOST_NAME = '192.168.10.36' # !!!REMEMBER TO CHANGE THIS!!!
PORT_NUMBER = 8080 # Maybe set this to 9000.

def getJsonTest():
    t1 = datetime.datetime.now()
    t2 = datetime.datetime.now()

    json_data = {"classifier":None,"Time":str(t2-t1)}
    out = 0

    if out == 0:
        json_data["classifier"] = "CAN"
    elif out == 1:
        json_data["classifier"] = "PET"
    else:
        json_data["classifier"] = "ETC"

    print(json_data)

    return json.dumps(json_data)

def getResult(s, model):
    
    """Respond to a POST request."""
    content_len = int(s.headers.getheader('content-length',0))
    post_body = s.rfile.read(content_len)

    """String:'data:image/png;base64,', it must be delete before base64 decode."""
    start = post_body.find('base64,')
    data = post_body[start+7:(len(post_body)-2)]
    """If data has a space, it will be change '+'."""
    data.replace(' ','+')

    filedata = base64.b64decode(data)

    f= open("./jskim8_wow.png","wb")
    f.write(filedata)
    f.close()

    t1 = datetime.datetime.now()
    out = model.test_net_single('./jskim8_wow.png')
    t2 = datetime.datetime.now()
    print('[Classify Time]: ' + str(t2-t1))
    print("Model :{}".format(out))

    json_data = {"classifier":None,"time":str(t2-t1)}

    if out == 0:
        json_data["classifier"] = "CAN"
    elif out == 1:
        json_data["classifier"] = "PET"
    else:
        json_data["classifier"] = "ETC"

    print(json_data)

    return json.dumps(json_data)


def getSelfResult(s, camera, model):
    camera.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
    camera.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)
    ret, frame = camera.read()

    img_name = "./jskim8_get.png"
    cv2.imwrite(img_name, frame)

    t1 = datetime.datetime.now()
    out = model.test_net_single(img_name)
    t2 = datetime.datetime.now()

    print('[Classify Time]: ' + str(t2-t1))
    print("Model :{}".format(out))

    json_data = OrderedDict()

    if out == 0:
        json_data["classifier"] = "CAN"
    elif out == 1:
        json_data["classifier"] = "PET"
    else:
        json_data["classifier"] = "ETC"

    print(json_data)

    return json_data


def getImage(s):
    model = Neurogenie()
    
    """Respond to a POST request."""
    content_len = int(s.headers.getheader('content-length',0))
    post_body = s.rfile.read(content_len)

    """String:'data:image/png;base64,', it must be delete before base64 decode."""
    start = post_body.find('base64,')
    data = post_body[start+7:(len(post_body)-2)]
    """If data has a space, it will be change '+'."""
    data.replace(' ','+')

    filedata = base64.b64decode(data)

    f= open("./jskim8_wow.png","wb")
    f.write(filedata)
    f.close()
    model.test_net_single('./jskim8_wow.png')

    f = open("./jskim8_wow_o.png","r")
    cls_return_img = f.read()
    returnData = base64.b64encode(cls_return_img)
    returnData = "data:image/png;base64," + returnData
    f.close()
        
    print(returnData)

    s.send_response(200)
    s.send_header('Content-type', 'image/jpeg')
    s.end_headers()
    s.wfile.write(returnData)

    return returnData

class MyHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    superbin = Neurogenie()
    camera = cv2.VideoCapture(0)

    def __init__(self,request, client_address,server):
        BaseHTTPServer.BaseHTTPRequestHandler.__init__(self,request, client_address,server)
    def do_HEAD(s):
        s.send_response(200)
        s.send_header("Content-type", "text/html")
        s.end_headers()

    def do_OPTIONS(s):
        s.send_response(200, "ok")
        s.send_header('Access-Control-Allow-Credentials', 'true')
        s.send_header('Access-Control-Allow-Origin', '*')
        s.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        s.send_header("Access-Control-Allow-Headers", "X-Requested-With, Content-type")
        s.end_headers()

    def do_GET(s):
        """Respond to a GET request."""
        s.send_response(200)
        s.send_header('Access-Control-Allow-Credentials', 'true')
        s.send_header('Access-Control-Allow-Origin', '*')
        s.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        s.send_header("Access-Control-Allow-Headers", "X-Requested-With, Content-type")
        s.send_header("Content-type", "text/html")
        s.end_headers()

        if s.path == "/hello":
            s.wfile.write("<html><head><title>Hello, world</title></head>");
            s.wfile.write("<body><p>Hello, world.</p>")
            s.wfile.write("</body></html>")
        elif s.path == "/jetson/cls/self":
            s.send_response(200)
            s.send_header('Content-type', 'application/json')
            s.end_headers()
            result = getSelfResult(s,MyHandler.camera,MyHandler.superbin)
            s.wfile.write(result)
        else:
            s.wfile.write("<html><head><title>Title goes here.</title></head>")
            s.wfile.write("<body><p>This is a test.</p>")
            s.wfile.write("<p>You accessed path: %s</p>" % s.path)
            s.wfile.write("</body></html>")
    
    def do_POST(s):
        s.send_response(200)
        s.send_header('Access-Control-Allow-Credentials', 'true')
        s.send_header('Access-Control-Allow-Origin', '*')
        s.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        s.send_header("Access-Control-Allow-Headers", "X-Requested-With, Content-type")
        
        if s.path == "/jetson/cls/result":
            s.send_header('Content-type', 'application/json')
            s.end_headers()
            result = getResult(s,MyHandler.superbin)
            s.wfile.write(result)
        elif s.path == "/jetson/cls/image":
            s.send_response(200)
            s.send_header('Content-type', 'image/jpeg')
            s.end_headers()
            result = getImage(s)
            s.wfile.write(result)
        elif s.path == "/jsontest":
            s.send_response(200)
            s.send_header('Content-type', 'application/json')
            s.end_headers()
            result = getJsonTest()
            s.wfile.write(result)
        else:
            s.send_response(200)
            s.send_header('Content-type', 'application/json')
            s.end_headers()
            s.wfile.write("{'error':'unknown'}")
            

if __name__ == '__main__':
    server_class = BaseHTTPServer.HTTPServer
    httpd = server_class((HOST_NAME, PORT_NUMBER), MyHandler)
    print time.asctime(), "Server Starts - %s:%s" % (HOST_NAME, PORT_NUMBER)
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    print time.asctime(), "Server Stops - %s:%s" % (HOST_NAME, PORT_NUMBER)

