vowels = ['A','E','I','O','U']

def minion_game(string):
    # your code goes here
    stuartScore = 0
    kevinScore = 0

    combinationSize = len(string)

    for i in range(0,len(string)):
        if string[i] in vowels:
            kevinScore += combinationSize
        else:
            stuartScore += combinationSize
        
        combinationSize -= 1

    if stuartScore > kevinScore:
        print("Stuart {}".format(stuartScore))
    elif stuartScore < kevinScore:
        print("Kevin {}".format(kevinScore))
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)