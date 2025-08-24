a = list(map(int, input().split()))

def selection_sort(list1):
    longs = len(list1)

    for i in range(longs - 1):
        idx = i

        for j in range(i, longs):
            if list1[j] < list1[idx]:
                idx = j

            if idx != i:
                list1[i], list1[idx] = list1[idx], list1[i]
                
result = selection_sort(a)
print(*a)