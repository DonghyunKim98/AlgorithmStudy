#include <bits/stdc++.h>
//2231¹ø
using namespace std;

void decomposition() {
	//setting
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//input
	int N;
	cin >> N;

	//process
	int sum=0;
	for (int i = 1; i < N; i++) {
		int temp = i;
		sum = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
}