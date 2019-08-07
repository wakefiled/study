stuartDict = {}
kevinDict = {}

vowels = ['A','E','I','O','U']

def count_substring(inputStr,stdStr):
    copyStr = stdStr
    result = 0
    index = 0

    while index>=0:
        index = copyStr.find(inputStr)
        if index == -1:
            break;
        
        result += 1
        copyStr = copyStr[index+1:]

    return result

def minion_game(string):
    # your code goes here
    stuartScore = 0
    kevinScore = 0
    j = 0

    while j < len(string):
        for i in range(0,len(string)):
            subEnd = i + j + 1
            if subEnd > len(string):
                break

            if string[i] in vowels:
                if kevinDict.get(string[i:subEnd]) == None:
                    kevinDict[string[i:subEnd]] = 1
                else:
                    kevinDict[string[i:subEnd]] += 1
                
                kevinScore+=1

            else:
                if stuartDict.get(string[i:subEnd]) == None:
                    stuartDict[string[i:subEnd]] = 1
                else:
                    stuartDict[string[i:subEnd]] += 1

                stuartScore+=1
        j+=1

    if stuartScore > kevinScore:
        print("Stuart {}".format(stuartScore))
    elif stuartScore < kevinScore:
        print("Kevin {}".format(kevinScore))
    else:
        print("Draw")


if __name__ == '__main__':
    s = input()
    minion_game(s)