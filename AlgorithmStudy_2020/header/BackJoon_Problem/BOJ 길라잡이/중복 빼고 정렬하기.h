#include <bits/stdc++.h>
//10867번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	//0~1000
	int positivie_arr[1001] = { 0, };
	//-1000~-1
	int negative_arr[1001] = { 0, };
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp < 0) {
			temp *= -1;
			if (negative_arr[temp] != 0) continue;
			else negative_arr[temp] = 1;
		}
		else {
			if (positivie_arr[temp] != 0) continue;
			else positivie_arr[temp] = 1;
		}
	}
	//음수 출력
	for (int i = 1000; i > 0; i--) {
		if (negative_arr[i] == 1) {
			cout << i*-1 << ' ';
		}
	}

	//양수 출력
	for (int i = 0; i <= 1000; i++) {
		if (positivie_arr[i] == 1) {
			cout << i << ' ';
		}
	}
}

/*
	위상정렬(Counting Sort)
*/