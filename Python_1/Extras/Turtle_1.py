import turtle 
  
# screen object 
sc = turtle.Screen()    
  
# turtle object 
pen = turtle.Turtle()   
  
  
# Driver Code 
# colors 
col = ['violet', 'indigo', 'blue', 'green',  
       'yellow', 'orange', 'red'] 
  
# screen size 
sc.setup(500,500)  
  
# screen color 
sc.bgcolor('black') 
  
# turtle size 
pen.pensize(4)  
  
# turtle object 
pen.speed(20)     
  
# integer variable  
# for accessing colors 
i = 0
  
# loop to draw 30 circles  
for angle in range(0, 360, 12): 
    
  # color of circle 
  pen.color(col[i])   
    
  if i == 6:            
    i = 0
      
  else: 
    i += 1
      
  # Set the orientation of 
  # the turtle to angle 
  pen.seth(angle)  
    
  # circle of radius 80 
  pen.circle(80)  
    
# hide the turtle 
pen.ht()
