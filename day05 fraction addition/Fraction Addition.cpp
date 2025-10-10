#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sumn = 0, sumd = 1; // 储存结果
    while (n--) {
        int num, deno;
        char slash; // 用于去掉/
        cin >> num >> slash >> deno;
        sumn = sumn * deno + sumd * num;
        sumd = sumd * deno;
    }
    // 用欧几里得法求最大公约数gcd
    int a = sumd, b = sumn, c;
    while (a != 0) {
        c = a; a = b%a; b = c;
    }
    int gcd = b;
    sumd /= gcd;
    sumn /= gcd;
    if (sumd > 1)
        cout << sumn << '/' << sumd << endl;
    else
        cout << sumn << endl;
    return 0;
}