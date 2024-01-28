def func(*args,sep='/'):
    """l=[]
    l.append(sep.join(args))
    return l"""
    return sep.join(args)
str1=func("Hello","Bye","World")
print(str1)
