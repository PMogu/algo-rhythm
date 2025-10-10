def recur (n: int) -> int:
    if n > 0:
        recur (n-1)
        print (n)
        recur (n-2)

recur(4)