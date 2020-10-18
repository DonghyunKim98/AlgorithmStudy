#include <bits/stdc++.h>
//1436¹ø ¹®Á¦
using namespace std;



void Movie() {
	int N;
	cin >> N;

	int result = 665;

	while (N > 0) {
		result++;
		int temp = result;
		vector<int> digit;
		int cnt=0;
		while (temp > 0) {
			int current_digit = temp % 10;
			if (current_digit == 6) {
				cnt++;
				if (cnt == 3) break;
			}
			else cnt = 0;
			temp /= 10;
		}
		if (cnt == 3) N--;
	}

	cout << result << endl;
}