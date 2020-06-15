#include <bits/stdc++.h>
//2581번 문제
using namespace std;

void Prime() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool prime_number[10001];
	fill_n(prime_number, 10001, true);
	//1은 소수가 아님
	prime_number[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (prime_number[i] == false) continue;
		for (int j = i * 2; j <= 10000; j+=i) {
			prime_number[j] = false;
		}
	}


	int first, last;
	cin >> first>> last;
	
	int minimum;
	int total=0;
	int Count=0;
	for (int i = first; i <= last; i++) {
		if (prime_number[i] == true) {
			if (Count == 0) {
				Count++;
				minimum = i;
			}
			total += i;
		}
	}
	if (total) {
		cout << total << "\n";
		cout << minimum;
	}
	else
		cout << -1;
}