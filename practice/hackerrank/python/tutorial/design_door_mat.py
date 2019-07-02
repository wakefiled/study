# Enter your code here. Read input from STDIN. Print output to STDOUT

if __name__ == "__main__":
    arr = list(map(int, input().split()))
    height = arr[0]
    width = arr[1]
    a = "---"
    b = ".|."
    WELCOME = "WELCOME"
    half_h = height//2

    for i in range(0,half_h):
        print( a*(half_h-i) + b*(2*i+1) + a*(half_h-i) )
    
    print(WELCOME.center(width,'-'))

    for i in range(0,half_h):
        print( a*(i+1) + b*(2*(half_h-i)-1) + a*(i+1) )
