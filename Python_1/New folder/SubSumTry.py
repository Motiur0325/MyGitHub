from functools import reduce
def subArraySum(arr, n, s): 
    print(arr)
    arr.append(0)
    print(arr)
    for i in range(0,n):
        for j in range(i,n):
            ans=reduce(lambda i,j:i+j,arr)
            print(ans)
n=5
s=12
a=[1,2,3,7,5]
subArraySum(a,n,s)
