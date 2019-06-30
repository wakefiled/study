if __name__ == '__main__':
    N = int(input())
    result = []

    for i in range(N):
        test = list(map(str,str(input()).split()))

        if test[0] == 'insert':
            result.insert(int(test[1]), int(test[2]))
        elif test[0] == 'print':
            print(result)
        elif test[0] == 'remove':
            result.remove(int(test[1]))
        elif test[0] == 'append':
            result.append(int(test[1]))
        elif test[0] == 'sort':
            result.sort()
        elif test[0] == 'pop':
            result.pop()
        elif test[0] == 'reverse':
            result.reverse()