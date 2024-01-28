def fact(n):
    if n==1:
        return n
    else:
        return n*fact(n-1)
myTuple=(1,2,3,4,5,6)
result=map(fact,myTuple)
print(list(result))
