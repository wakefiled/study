def getAlpahString(alpha, size):
    result = ""

    for i in range(size):
        if i%2 == 0:
            result = result + alpha
            if (i+1)/size <= 0.5:
                alpha = chr(ord(alpha) -1)
            else:
                alpha = chr(ord(alpha) +1)
        else:
            result = result + '-'

    return result

def print_rangoli(size):
    # your code goes here
    top = size-1
    bottom = size-1
    alphaA = 97

    a = "--"
    start_alpha = chr(alphaA + size-1)

    for i in range(0,top):
        print (a*(top-i) + getAlpahString(start_alpha, ((4*i)+1)) + a*(top-i))

    print (getAlpahString(start_alpha, (4*top)+1))

    for i in range(bottom):
        print (a*(i+1) + getAlpahString(start_alpha, (4*(bottom-i-1)+1)) + a*(i+1))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)