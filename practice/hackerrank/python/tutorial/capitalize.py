#!/bin/python3

# Complete the solve function below.
"""
def solve(s):

    list_w = s.split()
    result = ""

    for word in list_w:
        result += word[0].upper() + word[1:] + " "

    result = result[0:len(result)-1]

    return result
"""

def solve(s):

    result = "" 
    startWord = True

    for i in range(0,len(s)):
        if s[i] == ' ':
            startWord = True
            result += s[i]
            continue

        if startWord == True:
            startWord = False
            result += s[i].upper()
        else:
            result += s[i]

    return result

if __name__ == '__main__':
    s = input()
    result = solve(s)

    print(result)
