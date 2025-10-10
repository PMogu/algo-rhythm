# 线性查找（哨兵法）

from typing import Any, Sequence
import copy

def seq_search(seq: Sequence, key: Any) -> int:
    a = copy.deepcopy(seq)
    a.append(key)

    i = 0
    while True:
        if a[i] == key:
            break
        i += 1
    return -1 if i == len(seq) else i

if __name__ == '__main__':
    num = int(input('元素个数：'))
    x = [None] * num

    for i in range(num):
        x[i] = int(input(f'x[{i}]: '))

    ky = int(input('目标值：'))

    idx = seq_search(x, ky)

    if idx == -1:
        print('不存在与该值相等的元素。')
    else:
        print(f'元素下标为x[{idx}]')