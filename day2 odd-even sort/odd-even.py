a = list(map(int, input().split()))
sorted = False
while not sorted:
    sorted = True
    for i in range(1, len(a) - 1, 2):
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]
            sorted = False
    for i in range(0, len(a) - 1, 2):
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]
            sorted = False
print(*a)