point=(0,10)
match point:
    case (0,0):
        print("Point is at Origin")
    case (0,y):
        print(f"Y={y)")
    case (x,0):
        print(f"X={x}")
    case (x,y):
        print(f"X={x}, Y={y}")
    case _:
        print("Input Error")
