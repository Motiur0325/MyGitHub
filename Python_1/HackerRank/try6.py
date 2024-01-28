# Enter your code here. Read input from STDIN. Print output to STDOUT
N=int(input())
Stamp=set()
for i in range(N):
    Stamp.add(input())
print(len(Stamp))
