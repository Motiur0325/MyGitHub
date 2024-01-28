import string
from collections import Counter

rank=list()

def rank_list(x,y,alpha):
    if y==1:
        return alpha[x-1]
    for i in alpha:
        count=1
        for j in range(1,y):
            a=i
            for k in range(count,len(alpha)):
                if alpha[k] not in a:
                    a=a+alpha[k]
                    if len(a)==y and a not in rank:
                        rank.append(a)
                        l=list(a)
                        l.pop()
                        a=str()
                        for m in l:
                            a=a+m
            count+=1
    return rank[x-1]
        
alpha=list(string.ascii_lowercase)
x=int(input('Enter Rank :  '))
y=int(input('Enter String length : '))
print(rank_list(x,y,alpha))
print(rank)
