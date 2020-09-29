#include <bits/stdc++.h>
//2749번 문제
using namespace std;
long long a[1500050];
int m = 1000000;

void fibonacci() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 0; i < 1500000; i++) {
        a[i + 2] = (a[i + 1] + a[i]) % m;
    }
}

void solution() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    fibonacci();
    cout << a[n % 1500000] << "\n";

}
/*
    1)피보나치수는 150만을 기준으로 100만으로 나눈 나머지가 반복됨.
    2)https://egg-money.tistory.com/78 참고하듯, 피보나치 수열은 행렬로 바꿀 수 있음
*/