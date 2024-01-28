# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
K=int(input())
list1=list(map(int,input().split()))
set1=set(list1)
print(list1)
dict1=Counter(set1)
dict2=Counter(list1)
print(dict1,"\n",dict2)
for i,j in dict1.copy().items():
    print(i,j," : ",dict2[i])
    if dict2[i]==j:
        print(dict2[i])
