import operator

if __name__ == '__main__':

    students = []
    result = []
    
    second_low_score = 100

    for i in range(int(input())):
        name = input()
        score = float(input())

        if i == 0:
            min_score = score
        elif score < min_score:
            second_low_score = min_score
            min_score = score
        elif score < second_low_score and score > min_score:
            second_low_score = score

        students.append([name, score])

    for name, score in students:
        if score == second_low_score:
            result.append([name,score])

    result.sort(key=operator.itemgetter(0))

    for name, score in result:
        print(name)

