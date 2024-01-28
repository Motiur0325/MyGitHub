myPow=(0,1,4,9,16,25)
print(myPow)
print(len(myPow))
n=int(input('Enter no. to check : '))
myBool=False
for i in range(0,len(myPow)):
    if myPow[i]==n:
        myBool=True
        break;
    else:
        continue
if myBool==True:
    print('P')
else:
    print('A')
print(myPow[3])
