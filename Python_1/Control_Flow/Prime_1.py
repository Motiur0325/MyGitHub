for n in range(1,20):
    for x in range(2,n):
        if n%x==0:
            print(n," is Not a Prime")
            break
    else:
        print(n," is Prime")
