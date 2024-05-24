#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll A, B, C;

ll divConq(ll 제곱남은거)
{
    if (제곱남은거 == 0)
        return 1;
    else if (제곱남은거 == 1)
        return A % C;

    ll half = divConq(제곱남은거 / 2) % C;
    // 제곱남은거 홀수
    if (제곱남은거 % 2)
        return ((half * half % C) * (A % C)) % C;

    else
        return (half * half) % C;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> A >> B >> C;

    cout << divConq(B) % C;
}