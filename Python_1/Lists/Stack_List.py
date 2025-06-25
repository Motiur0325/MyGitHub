stack=[]
def push(x):
    stack.append(x)
def pop():
    return stack.pop()
def display():
    print("\nStack :  ",end=" ")
    for key in stack:
        print(key,end=" ")
def stack_count():
    return len(stack)
while True:
    ch=input("""\n1.Push\t\t\tPress Any Key to Exit.......
2.Pop\n3.Display\n4.Count\n5.Stack_Top\t\tEnter Choice :  """)
    match ch:
        case '1':
            push(input("\t\t\tEnter Data :  "))
        case '2':
            print("\nPopped Value :  ",pop())
        case '3':
            #print("\n",stack)
            display()
        case '4':
            print("\nStack[count] :  ",stack_count())
        case '5':
            if len(stack)==0:
                print("\nStack Empty\n")
            else:
                print("\nStack[Top] :  ",stack[len(stack)-1])
        case _:
            exit()
