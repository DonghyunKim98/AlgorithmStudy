#include <bits/stdc++.h>
//10870�� ����
using namespace std;

int Recurrsion(int target) {
	if (target == 0) return 0;
	else if (target == 1) return 1;
	else if (target == 2) return 1;
	return Recurrsion(target - 1) + Recurrsion(target - 2);
}

void Fibonacci() {
	int N;
	cin >> N;
	cout << Recurrsion(N);
}