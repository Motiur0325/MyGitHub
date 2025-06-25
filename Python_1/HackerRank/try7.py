n=int(input())
set1=set(map(int,input().split()))
N=int(input())
for i in range(N):
    cmd=input()
    if 'pop' in cmd.split():
        print(set1.pop([0]))
    if 'remove' in cmd.split():
        l=cmd.split()
        print(l)
        set1.remove(int(l[1]))
    if 'discard' in cmd.split():
        l=list(cmd.split())
        print(l)
        set1.discard(int(l[1]))
print(sum(set1))
