def is_leap(year):
    leap = False
    
    # Write your logic here
    divided400 = year%400
    divided100 = year%100
    divided4 = year%4
    
    if divided400 == 0:
        leap = True
    elif divided100 == 0:
        leap = False
    elif divided4 == 0:
        leap = True
    else:
        leap = False

    return leap

year = int(input())