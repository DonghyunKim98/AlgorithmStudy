#include <bits/stdc++.h>
//2004번 문제
using namespace std;

int TwoCount(int);
int FiveCount(int);


void NumberOfZero() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int two_order = 0;
	int five_order = 0;

	five_order += FiveCount(N);
	if (M != 0) five_order -= FiveCount(M);
	if (N != M) five_order -= FiveCount(N - M);

	two_order += TwoCount(N);
	if (M != 0) two_order -= TwoCount(M);
	if (N != M) two_order -= TwoCount(N - M);

	cout << min(two_order, five_order);

}


int TwoCount(int num) {
	int cnt = 0;
	
	for (long long i = 5; num / i >= 1; i *= 5)
		cnt += num / i;
	
	return cnt;
}


int FiveCount(int num) {
	int cnt = 0;
	
	for (long long i = 2; num / i >= 1; i *= 2)
		cnt += num / i;

	return cnt;
}
/*
	단순한 반복문으로는 시간 초과 => 반복문에서 iterator의 증가폭을 늘려준다!
*/