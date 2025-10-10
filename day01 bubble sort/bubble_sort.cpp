#include <iostream>
using namespace std;
int main(){
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i]; // 存放在数组中
    }
    for (int i = 0; i < n - 1; i++) { // 外层循环：第 i 趟冒泡
        for (int j = 1; j < n - i; j++) { // 内层循环：只在未排序部分内相邻比较
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}