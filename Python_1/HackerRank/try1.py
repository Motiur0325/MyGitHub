n=int(input())
l=[]
for i in range(n):
    x=str(input())
    y=float(input())
    l.append([x,y])
m=100.0
l_min=min(l,key=lambda x:x[1])
for w in l:
    if w[1]<=m and w[1]!=l_min[1]:
        m=w[1]
second=[]
for w in l:
    if w[1]==m:
        second.append([w[0],w[1]])
second=sorted(second,key=lambda x:x[0])
for i in second:
    print(i[0])
