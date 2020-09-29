#include <bits/stdc++.h>
//10830번 문제
//https://seokjin2.tistory.com/9 참고
using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> matrix;
const int MAX = 5;
ll N,B;
matrix arr(MAX,vector<ll>(MAX));

matrix operator*(const matrix& a, const matrix& b) {
	ll size = a.size();
	matrix ret(size, vector<ll>(size));
	for (ll i = 0; i < size; i++) {
		for (ll j = 0; j < size; j++) {
			for (ll k = 0; k < size; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= 1000;
		}
	}
	return ret;
}

matrix pow_(matrix a, ll n) {
	ll size = a.size();
	matrix ret(size, vector<ll>(size));
	for (ll i = 0; i < size; i++) { //단위 행렬
		ret[i][i] = 1;
	}
	//loop문으로 분할정복 구현
	while (n > 0) {
		if (n % 2 == 1) {
			ret = ret * a;
		}
		n /= 2;
		a = a * a;
	}
	return ret;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	matrix result=pow_(arr,B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}