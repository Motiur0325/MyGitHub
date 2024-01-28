from collections import deque
l=[1,2,3,4,5,6]
queue=deque(l)
print(queue)
queue.append(7)
queue.append(8)
print(queue)
print(queue.popleft())
print(queue.pop())
