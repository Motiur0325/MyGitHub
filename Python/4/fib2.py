def fib2(n):
    myFib=[]
    a,b=0,1
    while a<n:
        myFib.append(a)
        a,b=b,a+b
    return myFib
print(fib2(50))
