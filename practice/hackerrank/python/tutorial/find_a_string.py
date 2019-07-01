def count_substring(string, sub_string):
    n = 0
    sub_len = len(sub_string)

    for i in range(0, len(string)-sub_len+1):
        if string[i:i+sub_len] == sub_string:
            n+=1
  
    return n

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
