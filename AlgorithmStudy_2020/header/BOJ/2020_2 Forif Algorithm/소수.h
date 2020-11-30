#include <bits/stdc++.h>
// 1312번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B, N;
	cin >> A >> B >> N;
	while (true) {
		N--;
		A %= B;
		A *= 10; // 뒤에 0 붙이기 -> 소수점이 내려가니깐
		if (N == 0) {
			cout << A / B;
			return;
		}
	}
}
/*
	나누고 난 나머지를 나눈다
	O(n) 으로 푸는건가?
*/