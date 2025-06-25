def print_formatted(n):
    # your code goes here
    sp=len((bin(n))[2:])
    for i in range(1,n+1):
        print(str(i).rjust(sp,' '),((oct(i))[2:]).rjust(sp,' '),((hex(i))[2:]).rjust(sp,' '),((bin(i))[2:]).rjust(sp,' '))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
