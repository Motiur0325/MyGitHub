# Enter your code here. Read input from STDIN. Print output to STDOUT
M=int(input())
list1=list(map(int,input().split()))
set1=set(list1)
N=int(input())
list2=list(map(int,input().split()))
set2=set(list2)
set3=(set1.union(set2)).difference(set1.intersection(set2))
for i in sorted(set3):
    print(i)
