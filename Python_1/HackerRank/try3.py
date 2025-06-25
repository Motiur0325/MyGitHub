def average(array):
    new_array=set(array)
    avg=sum(new_array)/len(new_array)
    return('%.3f'%avg)

if __name__ == '__main__':
    arr = [161,182,161,154,176,170,167,171,170,174]
    result = average(arr)
    print(result)
