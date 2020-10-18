#include <bits/stdc++.h>
//16464번 문제
using namespace std;
typedef long long ll;
bool check(ll num) {
	while (num > 1) {
		if (num % 2 == 1) return true;
		num /= 2;
	}
	return false;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//전처리

	int N;
	cin >> N;
	while (N--) {
		ll K;
		cin >> K;
		if (check(K)) cout << "Gazua\n";
		else cout << "GoHanGang\n";
	}
}

/*
	-> 홀수는 무조건 됨
	-> 짝수는??
		=>2의 거듭제곱만 아니면 됨
		why?) 짝수가 3의 배수 -> k/3 -1, k/3 , k/3 +1
			  짝수가 5의 배수 -> k/5 -2 , k/5 -1, k/5, k/5 +1, k/5 +2 ...
			  => 이런식이 되어 2의 거듭제곱만 제외하고 전부 되게 되어있음
*/