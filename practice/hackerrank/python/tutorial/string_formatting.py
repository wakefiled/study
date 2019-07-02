def print_formatted(number):
    # your code goes here
    string = "{0:b}".format(number)
    width = len(string)-1

    for i in range(1,number+1):
        print("{0:d}".format(i).rjust(width),"{0:o}".format(i).rjust(width), "{0:X}".format(i).rjust(width), "{0:b}".format(i).rjust(width))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)

