def fx(n,myList=None):
    if myList==None:
        myList=[]
    myList.append(n)
    return myList
print(fx(1))
print(fx(2))
print(fx(3))
