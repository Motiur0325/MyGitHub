def subArraySum(arr, n, s): 
    ans=list()
    print(arr)
    arr.append(0)
    print(arr)
    for i in range(0,n):
        for j in range(i,n):
            print(sum(range(arr[i],arr[j+1])))
            if sum(range(arr[i],arr[j+1]))==s:
                ans.append(i+1)
                ans.append(j+1)
                return ans
    return [-1]
n=5
s=12
a=[1,2,3,7,5]
print(subArraySum(a,n,s))
