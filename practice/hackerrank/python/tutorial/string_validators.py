if __name__ == '__main__':
    s = input()
    result = [False, False, False, False, False]

    for c in s:
        if c.isdigit() == True:
            result[0] = True
            result[2] = True
        if c.isalpha() == True:
            result[0] = True
            result[1] = True
            if c.islower() == True:
                result[3] = True
            else:
                result[4] = True
    
    for value in result:
        print(value)
