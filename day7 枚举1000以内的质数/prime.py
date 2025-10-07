counter = 0 # 乘法运算和除法运算的次数
ptr = 0 # 得到的质数的个数
prime = [None] * 500

prime[ptr] = 2
ptr += 1
prime[ptr] = 3
ptr += 1

for n in range(5, 1001, 2): # 判断对象只有奇数
    i = 1
    while prime[i] * prime[i] <= n: # 质数n不能被小于等于n的平方根的任意质数整除
        counter += 2
        if n % prime[i] == 0:
            break
        i += 1
    else:
        prime[ptr] = n
        ptr += 1
        counter += 1
        
    for i in range(ptr):
        print(prime[i])

print(f'执行乘法运算和除法运算的次数: {counter}')