# 二分查找

from typing import Any, Sequence

def bin_search(a: Sequence, key: Any) -> int:
    pl = 0
    pr = len(a) - 1

    while True:
        pc = (pl + pr) // 2
        if a[pc] == key:
            return pc
        elif a[pc] < key:
            pl = pc + 1
        else:
            pr = pc - 1
        if pl > pr:
            break
    return -1

if __name__ == '__main__':
    num = int(input('元素个数：'))
    x = [None] * num

    print('请按照升序输入数据。')

    x[0] = int(input('x[0]: '))

    for i in range(1, num):
        while True:
            x[i] = int(input(f'x[{i}]: '))
            if x[i] >= x[i - 1]:
                break

    ky = int(input('目标值：'))

    idx = bin_search(x, ky)

    if idx == -1:
        print('不存在与该值相等的元素。')
    else:
        print(f'元素下标为x[{idx}]')