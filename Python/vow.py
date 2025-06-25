myDict={'a':0,'e':0,'i':0,'o':0,'u':0}
myVow=['a','e','i','o','u']
def vow(a):
    for i in range(0,5):
        for j in range(0,(len(a))):
            if a[j]==myVow[i]:
                myDict[myVow[i]]+=1
    return myDict
n=input()
print(vow(n))
