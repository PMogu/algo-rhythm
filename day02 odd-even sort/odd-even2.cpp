#include <iostream>
using namespace std;
int main(){
  int a[10];
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  // 冒泡
  for (int i = 0; i < 9; i++){
    for (int j = 1; j < 10 - i; j++){
      bool leftIsEven = a[j - 1] % 2 == 0;
      bool rightIsEven = a[j] % 2 == 0;
      // 如果左边为偶数，右边为奇数，顺序也颠倒
      if ((leftIsEven && !rightIsEven) || (leftIsEven == rightIsEven && a[j - 1] > a[j])) {
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