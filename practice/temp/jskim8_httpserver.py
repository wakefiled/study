import time
import BaseHTTPServer
from single_test import Neurogenie
import base64
import shutil

HOST_NAME = '127.0.0.1' # !!!REMEMBER TO CHANGE THIS!!!
PORT_NUMBER = 9000 # Maybe set this to 9000.

class MyHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    def __init__(self,request, client_address,server):
        BaseHTTPServer.BaseHTTPRequestHandler.__init__(self,request, client_address,server)
    def do_HEAD(s):
        s.send_response(200)
        s.send_header("Content-type", "text/html")
        s.end_headers()
    def do_GET(s):
        """Respond to a GET request."""
        s.send_response(200)
        s.send_header("Content-type", "text/html")
        s.end_headers()
        s.wfile.write("<html><head><title>Title goes here.</title></head>")
        s.wfile.write("<body><p>This is a test.</p>")
        s.wfile.write("<p>You accessed path: %s</p>" % s.path)
        s.wfile.write("</body></html>")
    
    def do_POST(s):
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

        f = open("./jskim8_wow.png","wb")
        f.write(filedata)
        f.close()
        model.test_net_single('./jskim8_wow.png','o')

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

