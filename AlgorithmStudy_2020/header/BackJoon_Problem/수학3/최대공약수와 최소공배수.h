#include <bits/stdc++.h>
//2609번 문제
using namespace std;

void MaxAndMin() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	
	//최대 공약수 출력
	for (int i = min(A, B); i > 0; i--) {
		if (A % i == 0 && B % i == 0) {
			cout << i <<'\n';
			break;
		}
	}

	//최소 공배수 출력
	for (int i = max(A, B);; i++) {
		if (i % A == 0 && i % B == 0) {
			cout << i<<'\n';
			break;
		}
	}
}