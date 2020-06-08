#include <bits/stdc++.h>
using namespace std;

int Clock() {
    int H, M;
    cin >> H >> M;
    if (M >= 45) {
        cout << H << " " << M-45;
    }
    else {
        if (H == 0) {
            cout << "23 " << (M + 60) - 45;
        }
        else {
            cout << H - 1 << " " << (M + 60) - 45;
        }
    }
}