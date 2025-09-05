# C程序设计进阶
## C程序中的函数
### 函数的定义
常用函数
- 已知一个数，求平方根 r = sqrt(100.0);
- 已知底数x，幂指数y，求$x^y$ k = pow(x, y)
- 求一个字符串的长度 i = strlen (str1);
- 比较两个字符串的大小 v = strcmp (str1, str2)
- 把字符串转换为相应的证书 n = atoi (str1)

```c++
#include <iostream>
using namespace std;
int absolute(int n)
{
    if (n < 0)
        return (-n);
    else
        return n;
}

int main()
{
    int m = -123, result = 0;
    result = absolute(m);
    cout << result;
    return 0;
}
```

---

```c++
#include <iostream>
using namespace std;
float max(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    cout << max(3, 4);
    return 0;
}
```

函数调用的方式

函数的调用方式可分为以下三种
1. 作为独立语句
2. 作为表达式的一部分
3. 以实参形式出现在其他函数的调用中

函数不一定需要输入参数/返回值

函数是C程序的基本构成单位
- 一个C程序由一个或多个源程序文件组成
- 一个源程序文件可以由一个或多个函数组成

函数的类型：函数的返回值的数据类型

函数的声明
函数的原型 (signature) = 返回值类型 + 函数名 + 参数类型
函数在使用前都要声明 除非被调用函数的定义部分已经出现在主调函数之前
在C语言中 函数声明就是函数原型

### 函数的执行

函数的调用过程

```c++
#include <iostream>
using namespace std;
float max(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int m = 3, n = 4;
    float result = 0;
    // (1) 初始化max() (2) 传递参数 (3) 保存当前现场
    result = max (m, n);
    // (1) 接收函数的返回值 (2) 恢复现场，从断点处继续执行
    cout << result;
    return 0;
}
```

参数的传递
- 实参与形参具有不同的存储单元，实参与形参的数据传递时“值传递”
- 函数调用时，系统给形参分配存储单元，并将实参对应的值传递给形参

P.S. 实参与形参的类型必须相同或可以兼容

### 变量的作用域
- 局部变量：在函数内或块内定义，只在这个函数或块内起作用的变量
- 全局变量：在所有函数外定义的变量，它的作用域是从定义变量的位置开始到本程序文件结束

```c++
#include <iostream>
using namespace std;
int excel_number = 0;
void excel_count(float score)
{
    if (score > 85)
    {
        excel_number++;
    }
}
int main()
{
    float score = 0;
    for (int i = 0; i < 100; i++)
    {
        cin >> score;
        excel_count(score);
    }
    cout << excel_count << endl;
    return 0;
}
```

当全局变量与局部变量同名时，局部变量将在自己作用域内有效，它将屏蔽同名的全局变量

数组元素做函数参数


数组名做函数参数

```c++
#include <iostream>
using namespace std;
void change(int a[])
{
    a[0] = 30; a[1] = 50;
}
int main()
{
    int a[2] = {3, 5};
    change(a) 
    cout << a[0] << " " << a[1] << endl; // 30 50
    return 0;
}
```

**a（数组名）不是变量 是数组在内存中的地址**

### 函数应用事例
问题描述
给定从公元2000年1月1日开始逝去的天数，请编写程序给出这一天是哪天

- 注意闰年：闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年

- 注意每个月的天数不一样

输入输出要求
输入多组数据，每组一个正整数，表示过去的天数
对输入的每个天数，输出一行，包含对应的日期和星期。格式为：YYYY-MM-DD DayOfWeek
输入最后一行是-1，不必处理。可以假设结果的年份不会超过9999

思路
计算出星期几 => 判断是否闰年，减掉每年的天数 => 减掉每月的天数，直到剩下天数不够一月

```c++
#include <iostream>
using namespace std;

// 全局：输入的“自 2000-01-01 起过了多少天”（0 表示 2000-01-01）
int days;

// 函数声明（原型）
int get_dayofweek();       // 0..6 映射到 week 数组
int get_year();            // 计算年份，并消耗掉对应整年的天数
int get_month(int leap);   // 计算月份，并消耗掉对应整月的天数（返回 1..12）
inline bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

int get_dayofweek() {
    return days % 7; // 0=Saturday（与下方 week 数组一致）
}

int get_year() {
    int y = 2000;
    while (true) {
        if (isLeap(y)) {
            if (days >= 366) { days -= 366; y++; }
            else break;
        } else {
            if (days >= 365) { days -= 365; y++; }
            else break;
        }
    }
    return y;
}

int get_month(int leap) {
    int pmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; // 平年
    int rmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; // 闰年

    int j = 0;
    while (j < 12) {
        int len = (leap ? rmonth[j] : pmonth[j]);
        if (days >= len) { days -= len; j++; }
        else break;
    }
    return j + 1; // 1..12
}

int main() {
    int year, month, dayofweek;
    const char week[7][10] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

    while ((cin >> days) && days != -1) {
        // 注意：get_year/get_month 会“消耗”days，把它变成当月中的“已过天数”
        dayofweek = get_dayofweek();        // 先取星期（用原始 days）
        year      = get_year();             // 消耗整年
        int leap  = isLeap(year) ? 1 : 0;
        month     = get_month(leap);        // 消耗整月
        int day   = days + 1;               // days 现在是从 0 开始的“当月天数”，要 +1 变 1..31

        cout << year << "-" << month << "-" << day << " " << week[dayofweek] << '\n';
    }
    return 0;
}

```

全局变量
- 破坏了函数的“相对独立性”；
- 增加了函数之间的“耦合性”；
- 函数之间的交互不够清晰；

因此：不在非常必要的情况下，不要使用全局变量

## 函数中的递归

### 函数的嵌套调用
例：检查素数
main() => checkPrime(a) => sqrt(number)

- 函数不能嵌套定义
- 函数可以嵌套调用

例：求阶乘
- fact(n) = fact(n - 1)*n
- fact(1) = 1

```c++
#include <iostream>
using namespace
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n*fact(n-1);
}
int main(){
    cout << fact(4) << endl;
    return 0
}
```

什么是递归？
“一个函数在其定义中直接或间接调用自身的一种方法”

### 递归调用的过程

```c++
#include <iostream>
using namespace std;
int recur()
{
    char c'
    c = cin.get();
    if (c != '\n')
        recur();
    cout << c;
    return 0;
}
int main()
{
    recur(); // input: abc\n, output: \ncba
    return 0;
}
```

### 递归应用示例
#### 用递归完成递推
切饼
q(n) = q(n-1) + n
q(1) = 2
```c++
include <iostream>
using namespace std;
int q(int n)
{
    if (n == 0)
        return 1;
    else
        return (n+q(n-1));
}
int main()
{
    cout << q(4) << endl;
    return 0;
}
```

递推的关注点放在起始点条件
递归的关注点放在求解目标上
相同：重在表现第 i 次与第 i+1 次关系

斐波那契数列
```c++
int f(int n)
{
    if(n == 1)
        return 1;
    if (n == 2)
        return 1;
    else
        return(f(n-1) + f(n-2))
}
```

#### 模拟连续发生的动作
进制转换
```c++
void convert(int x)
{
    if ( (x/2) != 0)
    {
        convert(x/2);
        cout << x%2;
    }
    else
        cout << x;
}

int main()
{
    int x;
    cin >> x // 123
    convert(x); // 1111011
    return 0;
}
```

汉诺塔问题
```c++
void move(int m, char x, char y, char z)
{
    if (m == 1)
    {
        cout << "把一个盘子从" << x << "移动到" << z << endl;
    }
    else
    {
        move (m - 1, x, z, y);
        cout << "把一个盘子从" << x << "移动到" << z << endl;
        move (m - 1, y, x, z);
    }
}
int main() {
    int n;
    cout << "请输入盘数n = ";
    cin >> n;
    cout << "在三根柱子上移" << n << "只盘的步骤为: " << endl;
    move (n, 'A', 'B', 'C');
    return 0;
}
```

#### 进行自动分析

放苹果（难）
如果：M/苹果树 >= n/盘子数
有盘子空着: f(m, n) = f(m, n-1)
没盘子空着: f(m, n) = f(m-n, n)

```c++
int count(int m, int n)
{
    if (m <=1 | n <= 0) return 1;
    if (m < n)
        return count(m, m);
    else
        return count(m, n - 1) + count(m - n, n);
}
void main()
{
    int apples, plates;
    cin >> apples >> plates;
    cout << count(apples, plates)
}
```

逆波兰表达式（难）

```c++
double notation()
{
    char str[10];
    cin >> str;
    switch (str[0])
    {
        case '+': return notation() + notation();
        case '-': return notation() - notation();
        case '*': return notation() * notation();
        case '/': return notation() / notation();
        default: return atot(str);
    }
}
int main()
{
    cout << notation();
    return 0;
}
```

## 指针

变量的三要素
变量的地址（指向该变量的指针） 变量的值 变量的名字

可以利用取地址运算符“&”获取地址

通过资源地址（指针）访问变量

计算机通过指针操作变量

cout << *&c << endl;
cout << c << endl;

### 指针变量

专门用于存放指针的变量

定义一个指针变量 int *pointer;
int: 指针变量的基类型
*: 指针运算符pointer的类型
pointer: 指针变量的名字

```c++
int c = 76;
int *pointer; // 定义名字为pointer的指针变量
pointer = &c; // 将变量c的地址赋值给指针变量point 赋值后称指针变量pointer指向了变量c
```

#### 指针变量的使用
```c++
int c = 76;
int *pointer = &c;
```
则*pointerw为pointer所指向的存储单元的内容 (变量c)；

#### 示例
```c++
#include <iostream>
using namespace std;
int main()
{
    int iCount = 18;
    int *iPtr = &iCount;
    *iPtr = 58;
    cout << iCount << endl; // 58
    cout << iPtr << endl; // 0028FB10
    cout << &iCount << endl; // 0028FB10
    cout << *iPtr << endl; // 58
    cout << &iPtr << endl; // 0028FB04
    return 0;
}
```
---
```c++
#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0, temp;
    int *p1 = NULL, *p2 = NULL; // 给指针变量赋予初始值
    cin >> a >> b; // 3 7
    p1 = &a;
    p2 = &b;
    if (*p1 < *p2)
    {
        temp = *p1; *p1 = *p2; *p2 = temp;
    }
    cout << "max = " << *p1 << ", min = " << *p2 << endl; // 7 3
    return 0;
}
```
---
```c++
#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0;
    int *p1 = NULL, *p2 = NULL;
    int *temp = NULL;
    cin >> a >> b; // 3 7
    p1 = &a;
    p2 = &b;
    if (*p1 < *p2)
    {
        temp = p1; p1 = p2; p2 = temp;
    }
    cout << "max = " << *p1 << ", min = " << *p2 << endl;
    return 0; // 7 3
}
```

&与*的运算优先级：与前置`++` `--` `逻辑非 (!)`同级 （同级从右往左运算）

#### 指针变量的`++` `--`

pointer++的含义

```c++
#include <iostream>
using namespace std;
int main() {
    int n = 0;
    int *p = &n; // 00C6FED8
    cout << p << endl;
    p++; // 00C6FEDC
    cout << p << endl;
    return 0;
}
```

假设：iPtr当前所存地址是0x00000100

若iPtr指向一个整型元素（占四个字节）
则 iPtr++ 等于 iPtr + 1 * 4 = 0x00000104

若iPtr指向一个实型元素（占四个字节）
则 iPtr++ 等于 iPtr + 1 * 4 = 0x00000104

若iPtr指向一个字符元素（占一个字节）
则 iPtr++ 等于 iPtr + 1 * 1 = 0x00000101

小结：
- 什么是“指针”
- 什么是“指针变量”
- *pointer 的含义
- pointer++的含义

#### 数组与指针

指向数组元素的指针

```c++
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = &a[3];
    cout << *p << endl; // 4
    *p = 100;
    cout << a[3] << endl; // 100
    return 0;
}
```

```c++
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {10, 11, 12, 13, 14};
    cout << a << endl; // 0017F754
    cout << *a << endl; // 10
    cout << &a[0] << endl; //  0017F754
    cout << a[0] << endl; // 10
    return 0;
}
```

- 数组名代表数组首元素的地址（数组名相当于指向数组第一个元素的指针）
- 数组名a不是变量 不能给a赋值

#### 用指针访问数组

```c++
#include <iostream>
using namespace std;
int main() {
    int a[5] = {10, 11, 12, 13, 14};
    int *p = NULL;
    cout << a << endl; // 00C5FCB4
    p = a;
    cout << p << endl; // 00C5FCB4
    cout << *p << endl; // 10
    cout << *p++ << endl; // 10 (指向11)
    cout << *p++ << endl; // 11 (指向12)
}
```

若定义数组int a[10]; 指针int *pointer;
则：pointer = a; 等价于pointer = &a[0];

数组访问
pointer + i; 等价于 a + i; 等价于 &a[i];
*(pointer + i) 等价于 *(a + i) 等价于 a[i]

表示形式
pointer[i] 等价于 *(pointer + i)

int *p = &a[0];
p可以指向数组的最后一个元素以外的元素
指针做加减运算时一定注意有效的范围

```c++
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = &a[3];
    *p = 100;
    cout << *p++ << endl; // 100
    cout << *p-- << endl; // 5
    cout << *--p << endl; // 3
    return 0;
}
```

倒置数组元素
```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a[10], *p = NULL, *q = NULL, temp;
    for (p = a; p < a + 10; p++)
        cin >> *p;
    for (p = a, q = a + 9; p < q; p++, q--)
    {
        temp = *p; *p = *q; *q = temp;
    }
    for (p = a; p < a + 10; p++)
        cout << setw(3) << *p;
    return 0;
}
```

#### 指向二维数组的指针

遍历数组元素

```c++
#include <iostream>
using namespace std;
int main()
{
    int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    int *p;
    for (p = &a[0][0]; p < &a[0][0] + 12; p++)
    {
        cout << p << ' ' << *p << endl;
    }
    return 0;
}
```

---

```c++
int main()
{
    int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    int (*p)[4], i, j;
    p = a;
    cin >> i >> j;
    cout << setw(4) << *(*(p+i)+j); // p[i][j]
    return 0;
}
```

p + i 等价于&a[i];
*(p + i) 等价于a[i]
*(p + i) +j  等价于a[i] + j
因为：a[i] + j 等价于 &a[i][j]
*(*(p + i) + j)等价于a[i][j]

### 字符串与指针

指向数组的指针
int a[10]; int = *p; p = a;

指向字符串的指针变量
char a[10]; char *p; p = a;

```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char a[] = "How are you?", b[20];
    char *p1, *p2
    for (p = a, p2 = b; *p1 != '\0'; p1++, p2++)
        *p2 = *p1;
    *p2 = '\0';
    cout << "string a is: " << a << endl;
    cout << "string b is: " << b << endl;
    return 0;
}
```

---

```c++
#include <iostream>
using namespace std;
int main()
{
    char buffer[10] = "ABC";
    char *pc;
    pc = "hello";
    cout << pc << endl; // hello
    pc++;
    cout << pc << endl; // ello
    cout << *pc <<< endl; // e
    pc = buffer; 
    cout << pc; // ABC
    return 0;
}
```

### 取地址与指针运算

```c++
#include <iostream>
using namespace std;
int main()
{
    int a[4] = {1, 3, 5, 7};
    cout << a << endl; // 0028F7C4
    cout << a+1 << endl; // 0028F7C8
    cout << &a << endl; // 0028F7C4
    cout << &a + 1 << endl; //0028F7D4
    cout << *(&a) << endl; // 0028F7C4
    cout << *(&a) + 1 << endl; // 0028F7C8 
    return 0;
}
```

### 二维数组名的含义

二维数组的定义
二维数组a[3][4]包含三个元素：a[0], a[1], a[2]
每个元素都是一个"包含四个整型元素"的数组

- 数组名相当于指向数组第一个元素的指针
- &E相当于把E的管辖范围上升了一个级别
- *E相当于把E的管辖范围下降了一个级别

```c++
int main()
{
    int a[3][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    cout<<"        a = "<<a<<endl;
    cout<<"    &a[0] = "<<&a[0]<<endl<<endl;

    cout<<"      a+1 = "<<a+1<<endl;
    cout<<" &a[0]+1 = "<<&a[0]+1<<endl<<endl;

    cout<<"       *a = "<<*a<<endl;
    cout<<"     a[0] = "<<a[0]<<endl;
    cout<<"&a[0][0] = "<<&a[0][0]<<endl<<endl;

    cout<<"    *a+1 = "<<*a+1<<endl;
    cout<<"  a[0]+1 = "<<a[0]+1<<endl;
    cout<<"&a[0][0]+1 = "<<&a[0][0]+1<<endl<<endl;

    return 0;
}

```

---

```c++
#include <iostream.h>
void main()
{
    int a[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    cout << "a = " << a << endl;
    cout << "&a[0] = " << &a[0] << endl << endl;

    cout << "a+1 = " << a+1 << endl;
    cout << "&a[0]+1 = " << &a[0]+1 << endl << endl;

    cout << "a[1] = " << a[1] << endl;
    cout << "&a[1] = " << &a[1] << endl;
    cout << "*(a+1) = " << *(a+1) << endl << endl;

    cout << "*a+1 = " << *a+1 << endl << endl;

    cout << "&a = " << &a << endl;
    cout << "&a+1 = " << &a+1 << endl;
}
```

### 指针做函数参数
```c++
#include <iostream>
using namespace std;
void Rank(int *q1, int *q2)
{
    int temp;
    if (*q1 < *q2)
    {
        temp = *q1;
        *q1 = *q2;
        *q2 = temp;
    }
}
int main()
{
    int a, b, *p1, *p2;
    cin >> a >> b;
    p1 = &a; p2 = &b;
    Rank (p1, p2)
    cout << a << ' ' << b << endl;
    return 0;
}
```

```c++
#include <iostream>
using namespace std;

void sum(int *p, int n)
{
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total += *p++;
    }
    cout << total << endl;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sum(a, 10);
    return 0;
}
```

---

```c++
#include <iostream>
using namespace std;

int sum(int array[], int n)
{
    for (int i = 0; i < 10 - 1; i++)
    {
        *(array + 1) = *array + *(array + 1);
        array++;
    }
    return *array;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(a, 10);
    return 0;
}
```

### 限制指针实参的功能

指向符号常量的指针

```c++
#include <iostream>
using namespace std;

int sum(const int array[], int n)
{
    for (int i = 0; i < 10 - 1; i++)
    {
        *(array + 1) = *array + *(array + 1); //  错误：不能给常量赋值
        array++;
    }
    return *array;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(a, 10);
    return 0;
}
```

符号常量声明语句
方式一：const 数据类型 常量名 = 常量值;
方式二：数据类型 const 常量名 = 常量值;

定义语句：const int *p

### 指针做函数返回值
```c++
#include <iostream>
using namespace std;
int *get(int arr[][4], int n, int m)
{
    int *pt;
    pt = *(arr + n - 1) + m - 1;
    return(pt);
}
void main() {
    int a[4][4] = 
    {1, 2, 3, 4,5 ,6 , 7, 8, 9}
    int *p
    p = get (a, 2, 3);
    cout << *p endl;
}
```

---

```c++
#include <iostream>
using namespace std;
int *getInt1()
{
    int Value1 = 20; // static int Value1 = 20;
    return &value1;
}
int *getInt2()
{
    int Value2 = 30; // static int Value2 = 30;
    return &value2;
}
int main(){
    int *p, *q;
    p = getInnt1();
    q = getInt2();
    cout << *p << endl; // 30
    return 0;
}
```

---

```c++
#include <iostream>
using namespace std;
int value1 = 20;
int value2 = 30;
int *getInt1()
{
    return &value1;
}
int *getInt2()
{
    return &value2;
}
int main(){
    int *p, *q;
    p = getInnt1();
    q = getInt2();
    cout << *p << endl; // 30
    return 0;
}
```

### 静态局部变量

函数中的局部变量的值在函数调用结束后不消失而保留原值
即其占用的存储单元不是放，在下一次该函数调用时，仍可继续使用该变量

## 结构体与链表

```c++
struct student
{
    int id;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30]
}; // 注意大括号后的";"
```

---

```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
int main()
{
    student mike = {123, {'m', 'i', 'k', 'e', '\0'}};
    mike.id_num = 20130000 + mike.id_num;
    for (int i = 0; mike.name[i] != '\0'; i++)
        mike.name[i] = toupper(mike.name[i]);
    cout << mike.id_num << ' ' << mike.name << endl;
}
```

### 结构体变量与函数

结构体变量赋值
```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
int main()
{
    student mike1 = {123, {'m', 'i', 'k', 'e', '\0'}}
    student mike2;
    mike2 = mike1;
    mike2.id_num = 20130000 + mike2.id_num;
    for (int i = 0; mike2.name[i] != '\0'; i++)
        mike2.name[i] = toupper(mike2.name[i]);
    cout << mike1.id_num << ' ' << mike1.name << endl; // 123 mike
    cout << mike2.id_num << ' ' << mike2.name << endl; // 20130123 MIKE
    return 0;
}
```

结构体变量做函数参数
```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
void renew(student one)
{
    one.id_num = 20130000 + one.id_num;
    for (int i = 0; one.name[i] != '\0'; i++)
        one.name[i] = toupper(one.name[i]);
    cout << one.id_num << ' ' << one.name << endl; // 20130123 MIKE
}
int main()
{
    student mike = {123, {'m', 'i', 'k', 'e', '\0'}}
    renew(mike);
    cout << mike.id_num << ' ' << mike.name << endl; // 123 mike
    return 0;
}
```

结构体变量做函数返回值
```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
student newone()
{
   student one = {20130123, {'M', 'I', 'K', 'E', '\0'}};
   return one;
}
int main()
{
    student mike = newone();
    cout << mike.id_num << ' ' << mike.name << endl; // 123 mike
    return 0;
}
```

### 结构体变量与指针
```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
}
int main()
{
    student mike = {123, {'m', 'i', 'k', 'e', '\0'}};
    student *one = &mike;
    cout << (*one).id_num << ' ' << (*one).name; // 123 mike
    cout << one->id_num << ' ' << one->name; // 指向运算符
    return 0;
}
```

---

```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
void renew(student *one)
{
    one->id_num = 20130000 + one->id_num;
    for (int i = 0; one->name[i] != '\0'; i++)
        one->name[i] = toupper(one->name[i]);
}
int main()
{
    student mike = {123, {'m', 'i', 'k', 'e', '\0'}}
    renew(&mike);
    cout << mike.id_num << ' ' << mike.name << endl; // 20130123 mike
    return 0;
}
```

---

结构体数组
```c++
#include <iostream>
using namespace std;
struct student
{
    int id_num;
    char name[10];
};
int main()
{
    student myclass[3] =
    {123, {'m', 'i', 'k', 'e', '\0'}
    133, {'t', 'o', 'm', '\0'}
    143, {'j', 'a', 'c', 'k', '\0'}};
    student *one = myclass;
    cout << one->id_num << ' ' << one->name << endl; // 123 mike
    one++;
    cout << one->id_num << ' ' << one->name << endl; // 133 tom
    reutnr 0;
}
```

结构体数据类型的特征与普通数据类型的特征是一致的

### 链表的定义

- 链表头：指向第一个链表节点的的指针
- 链表节点：链表中的每一个元素，包括：
  - 当前节点的数据
  - 下一个节点的地址
- 链表尾：不再指向其他节点的的节点，其地址部分放一个NULL，表示链表到此结束

链表可以动态地创建

- 动态地申请内存空间
int *pint = new int(1024);
delete pint;

int *pia = new int[4];
delete [] pia;

- 动态地 简历链表节点
struct student
{
    int id;
    student *next;
}

student *head;
head new student;

逐步建立链表

Step1:
head = new student;
student *temp = head;

Step2:
Cotinue?

Y:
temp->next = new student;
temp = temp->next
goto Step 2

N:
temp->next = NULL

```c++
student *create()
{
    student *head, *temp; int num, n = 0;
    head = new student;
    temp = head;
    cin >> num;
    while (num != -1)
    {
        n++;
        temp->id = num;
        temp->next = new student;
        temp=temp->next;
        cin >> num;
    }
    if (n == 0) head = NULL, else temp->next = NULL;
    return head
}
```

#### 链表的操作

链表元素的遍历
```c++
#incldue <iostream>
using namespace std;
struct student
{
    int id;
    student *next;
};
student * create();
int main()
{
    student *pointer = create();
    while (pointer->next != NULL)
    {
        cout << pointer->id << endl;
        pointer = pointer->next;
    }
    return 0;
}
```

删除链表节点
删除第一个节点
temp = head; head = head->next; delete temp;

删除中间节点
follow->next = temp->next; delete temp;

在链表中将值为n的元素删掉
```c++
linker *dele(student *head, int n)
{
    student *temp, *follow;
    temp = head;
    if (head == NULL) {
        return (head);                 // head为空，空表的情况
    }
    if (head->num == n) {              // 第一个节点是要删除的目标；
        head = head->next;
        delete temp;
        return (head);
    }
    while (temp != NULL && temp->num != n) {  // 寻找要删除的目标；
        follow = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "not found";           // 没寻找到要删除的目标；
    else {
        follow->next = temp->next;     // 删除目标节点；
        delete temp;
    }
    return (head);
}

```

插入节点
将节点unit插入链表：
插在最前面的情况
unit->next = head;
head = unit;

插在中间的情况
unit->next = temp;
follow->next = unit;

```c++
Student *insert(student *head, int n) {     // 插入结点值为 n 的结点
    student *temp, *unit, *follow;
    temp = head;
    unit = new student;
    unit->num = n;
    unit->next = NULL;

    if (head == NULL) {                     // 如果链表为空，直接插入
        head = unit;
        return(head);
    }

    // 寻找第一个不小于 n 或结尾的结点 temp
    while ((temp->next != NULL) && (temp->num < n)) {
        follow = temp;
        temp = temp->next;
    }

    if (temp == head) {                     // 如果 temp 为第一个结点
        unit->next = head;
        head = unit;
    }
    else {
        if (temp->next == NULL)             // 如果 temp 为最后一个结点
            temp->next = unit;
        else {                              // 如果 temp 为一个中间结点
            follow->next = unit;
            unit->next = temp;
        }
    }

    return(head);
}
```

双向链表
temp->num: 存放数据
temp->next: 指向下一个
temp->ahead: 指向前一个

删除一个节点
temp->ahead->next = temp->next;
temp->next->ahead = temp->ahead;

插入一个节点
unit->next = temp->next;
unit->ahead = temp;
temp->next->ahead = unit;
temp->next = unit;

```c++
#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *ahead;
    Node *next;
};

Node *Create(int N);
Node *Search(Node *head, int P);
Node *Release(Node *head, int M);

int main()
{
    int N, P, M = 0;               // N-起始节点数, P-开始节点
    cin >> N >> P >> M;            // 每次释放第M个节点
    Node *head = Create(N);        // 创建N个节点的环
    head = Search(head, P);        // 找到第P个节点
    while (head->next != head)     // 不断释放第M个元素
    {                              // 直到只剩一个元素
        head = Release(head, M);   // 释放第M个节点
    }
    cout << head->num;
    return 0;
}

```