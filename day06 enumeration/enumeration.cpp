#include <iostream>
using namespace std;
bool check(int P, int D, int T, int H) {
    int cntA = 0, cntB = 0, cntC = 0, cntD = 0;

    if (D == 1) cntA++;
    if (H == 4) cntA++;
    if (P == 3) cntA++;

    if (H == 1) cntB++;
    if (D == 4) cntB++;
    if (P == 2) cntB++;
    if (T == 3) cntB++;

    if (H == 4) cntC++;
    if (D == 3) cntC++;

    if (P == 1) cntD++;
    if (T == 4) cntD++;
    if (H == 2) cntD++;
    if (D == 3) cntD++;

    return (cntA == 1 && cntB == 1 && cntC == 1 && cntD == 1);
}

int main(){
    int P, D, T, H;
    for (P = 1; P <= 4; P++)
        for (D = 1; D <= 4; D++) if (D != P)
            for (T = 1; T <= 4; T++) if(T != P && T != D)
                for (H = 1; H <= 4; H++) if(H != P && H != D && H != T) {
                    if (check(P, D, T, H)) {
                        cout << P << endl;
                        cout << D << endl;
                        cout << T << endl;
                        cout << H << endl;
                    }
                }
                return 0;
}