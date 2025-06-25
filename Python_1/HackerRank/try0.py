arr=list(map(int,input().split()))
arr_max=-100
for i in arr:
    if i>=arr_max and i!=max(arr):
        arr_max=i
print(arr_max)
