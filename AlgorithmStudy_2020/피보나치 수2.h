#include <bits/stdc++.h>

using namespace std;

//2748�� ����

void Fibonacci() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	// Memoization Array
	long long* asw = new long long[N+1];
	//Base case ����
	asw[0] = 0, asw[1] = 1;
	//��ȭ��
	for (int i = 2; i <= N; i++) {
		asw[i] = asw[i - 2] + asw[i - 1];
	}
	cout << asw[N] <<endl;
}

