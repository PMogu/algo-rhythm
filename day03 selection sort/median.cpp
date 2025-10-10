#include <iostream>
using namespace std;

int main() {
    int N;
    int a[15000];

    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++) cin >> a[i];

        for (int i = 0; i < N; i++) {
            int min = i;
            for (int j = i + 1; j < N; j++) {
                if (a[j] < a[min]) min = j;
            }
            if (min != i) {
                int temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
        }

        int median;
        if (N % 2 == 1){
            median = a[N/2];
        }
        else {
            median = (a[N/2 - 1] + a[N/2]) / 2;
        }
        cout << median << endl;
    }
    return 0;
}