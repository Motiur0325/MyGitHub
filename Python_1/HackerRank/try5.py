# Enter your code here. Read input from STDIN. Print output to STDOUT
n,m=map(int,input().split())
set1=set(map(int,input().split()))
set2=set(map(int,input().split()))
set3=set(map(int,input().split()))
happiness=0
for i in set1:
    if i in set2:
        happiness+=1
    if i in set3:
        happiness-=1
print(happiness)
