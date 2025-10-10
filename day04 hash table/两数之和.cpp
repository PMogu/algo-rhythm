#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int x;
    unordered_map <int, int> hash;
    bool found = false;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (hash.count(k - x)) found = true;
        hash[x]++; // 存进哈希表
    }

    if (found) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}