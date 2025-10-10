from collections import deque

# 栈
stack = deque()
for x in [1, 2, 3]:
    stack.append(x)
while stack:
    print("Pop:", stack.pop())

# 队列
queue = deque()
for x in [1, 2, 3]:
    queue.append(x)
while queue:
    print("Dequeue", queue.popleft())