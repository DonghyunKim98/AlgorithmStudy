#include <bits/stdc++.h>
//2231번
using namespace std;

void decomposition() {
	//setting
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//input
	int N;
	cin >> N;

	//process
	//자리수 파악
	int Digit=0 , temp =N;
	while (N > 0) {
		N /= 10;
		Digit++;
	}
	int start = N - (Digit * 9);
	int end = N; 
	int sum;
	for (; start <= end; start++) {
		int temp = start;
		sum = temp;
		while (temp > 0) {
			int a = temp % 10;
			sum += a;
			temp /= 10;
		}
		if (sum == N) break;
		if (start == end) cout << "0";
	}
	cout << sum;
	//output
}