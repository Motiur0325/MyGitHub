def swap_case(s):
    a=str()
    for i in s:
        if i.islower():
            a+=i.upper()
        else:
            a+=i.lower()
    return a

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
