#include <bits/stdc++.h>
//1629�� ����
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
	O(N)���� Ǯ� TLE�� ������ ����
	O(log N)���� �ٲپ����
	X^a �� X^(a/2) * X^(a/2) �� �̿��ϸ� �ȴ�.
	������Ģ�� �ٰ��ؼ� a�� 0�� 1�϶��� ����ó�����ְ�, a�� ¦���� �ƴϸ� 1�� ���ִ� ������ �ؼ� ���̴�.
*/