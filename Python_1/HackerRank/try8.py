n=int(input())
set1=set(map(int,input().split()))
N=int(input())
for i in range(N):
    cmd1=input()
    cmd2=set(map(int,input().split()))
    if 'intersection' in cmd1.split()or cmd1.split('_'):
        set1=set1.intersection(cmd2)
    if 'update' in cmd1.split():
        set1=set1.union(cmd2)
    if 'symmetric' in cmd1.split()or cmd1.split('_'):
        set1=set1.union(cmd2).difference(set1.intersection(cmd2))
    if 'difference_update' in cmd1.split():
        set1=set1.difference(cmd2)
print(sum(set1))
