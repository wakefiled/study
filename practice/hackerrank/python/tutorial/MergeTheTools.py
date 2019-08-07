def get_u_str(string):
    list_c = [string[0]]
    u = string[0]

    for i in range(1, len(string)):
        if string[i] in list_c:
            continue
        
        list_c.append(string[i])
        u += string[i]
    
    return u

def merge_the_tools(string, k):
    # your code goes here

    for i in range(0,len(string),k):
        t = string[i:i+k]
        u = get_u_str(t)
        print(u)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)