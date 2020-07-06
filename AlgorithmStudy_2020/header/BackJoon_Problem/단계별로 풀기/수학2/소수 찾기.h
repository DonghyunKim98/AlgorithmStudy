#include <bits/stdc++.h>
//1978번 문제
using namespace std;


void Prime() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//일단 모든 소수를 검사.
	bool prime_number[1001];
	fill_n(prime_number, 1001, true);
	//1은 제외
	prime_number[1] = false;
	for (int i = 2; i <= 1000; i++) {
		//이미 소수가 아닌게 판명난적이 있으면 pass
		if (prime_number[i] == false) continue;
		//i 본인을 제외한 i*2 부터 소수가 아니므로 false값을 넣어준다.
		for (int j = i * 2; j <= 1000; j += i) {
			prime_number[j] = false;
		}
	}

	int total = 0;
	while (N > 0) {
		int temp;
		cin >> temp;
		if (prime_number[temp] == true) total += 1;
		N--;
	}

	cout << total;
}