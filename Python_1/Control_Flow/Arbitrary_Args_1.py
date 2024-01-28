def func(file,seperate,*args):
    file.write(seperate.join(args))
func('Hello.txt','/',"Bye","How","Why")
