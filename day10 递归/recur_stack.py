# 用栈模拟递归
def recur(n):
    s = []
    while True:
        if n > 0:
            s.append(n); n -= 1; continue
        if s:
            n = s.pop(); print(n); n -= 2; continue
        break

recur(4)