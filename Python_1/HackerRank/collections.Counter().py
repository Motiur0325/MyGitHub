from collections import Counter

def Sales(l,myList):
    sale=0
    while myList!=[]:
        if myList[0] in Counter(l).keys():
            sale+=myList[1]
            l.remove(myList[0])
        myList.pop(0)
        myList.pop(0)
    return sale
x=(int)(input())
l=list(map(int,input().split(" ")))
n=(int)(input())
myList=[]
for i in range(0,n):
    inp=list(map(int,input().split()))
    myList.extend(inp)
print(Sales(l,myList))
