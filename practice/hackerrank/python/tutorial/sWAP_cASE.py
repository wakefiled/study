def swap_case(s):

    result = ""

    for c in s:
        if c.isupper() == True:
            result = result + c.lower()
        else:
            result = result + c.upper()

    return result

if __name__ == '__main__':
    s = raw_input()
    result = swap_case(s)
    print result
