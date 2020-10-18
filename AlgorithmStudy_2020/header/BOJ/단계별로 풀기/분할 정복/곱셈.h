#include <bits/stdc++.h>
//1629번 문제
typedef long long ll;
using namespace std;
ll A, B, C;

ll pow_(ll x, ll m) {
	if (m == 0) return 1;
	else if (m == 1) return x;
	if (m % 2 == 1) return (pow_(x, m - 1) * x) % C;
	ll half = pow_(x, m / 2);
	half %= C;
	return (half * half) % C;
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	cout << pow_(A, B) % C;
}

/*
	O(N)으로 풀어도 TLE가 나오는 문제
	O(log N)으로 바꾸어야함
	X^a 는 X^(a/2) * X^(a/2) 를 이용하면 된다.
	지수법칙에 근거해서 a가 0과 1일때를 예외처리해주고, a가 짝수가 아니면 1을 빼주는 식으로 해서 말이다.
*/