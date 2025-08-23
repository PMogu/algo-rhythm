#include <iostream>
using namespace std;
int main(){
  int a[10];
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  // 把奇数放到数组左边，偶数放到数组右边
  int l = 0, r = 9; // 指向数组两端
  while (l <= r) {
    bool leftIsOdd = a[l] % 2 == 1;
    bool rightIsEven = a[r] % 2 == 0;
    if (leftIsOdd) {
      l++;
    } else if (rightIsEven) {
      r--;
    } else if (!leftIsOdd && !rightIsEven) {
      int temp = a[l];
      a[l] = a[r];
      a[r] = temp;
    }
  }
  // 左边冒泡
  for (int i = 0; i < l - 1; i++) {
    for (int j = 1; j < l - i; j++) {
      if (a[j - 1] > a[j]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }
  // 右边冒泡
  for (int i = l; i < 9; i++) {
    for (int j = l + 1; j < l + 10 - i; j++) {
      if (a[j - 1] > a[j]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }  
  for (int i = 0; i < 10; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}