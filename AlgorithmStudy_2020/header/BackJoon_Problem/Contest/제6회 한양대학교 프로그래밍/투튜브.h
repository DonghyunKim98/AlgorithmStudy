#include <bits/stdc++.h>
//17954번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int answer = 0, total = (2 * N) * (2 * N + 1) / 2;

	/*
	ex) n=5
	[10 1 2 3 9]
	[8  4 5 6 7]
	=> 7 6 5 4 8 9 3 2 1 10
	*/
	//0초
	total -= (2 * N) - 3;
	//1초~n-2초
	for (int i = (2 * N - 4); i >= N - 1; i--) {
		answer += total * (i - 2 * N + 5);
		total -= i;
	}
	//n-1초
	answer += total * (N - 1);
	total -= (2 * N) - 2;
	//n초
	answer += total * N;
	total -= (2 * N) - 1;
	//n+1초~2*n-2초
	for (int i = N - 2; i >= 1; i--) {
		answer += total * (2 * N - i - 1);
		total -= i;
	}
	//2*n-1초
	answer += total * (2 * N - 1);
	total -= 2 * N;

	cout << answer << '\n';
	cout << 2 * N << ' ';
	for (int i = 1; i <= N - 2; i++)
		cout << i << ' ';
	cout << 2 * N - 1 << '\n';
	cout << 2 * N - 2 << ' ';
	for (int i = N - 1; i <= 2 * N - 4; i++)
		cout << i << ' ';
	cout << 2 * N - 3;
}


/*
	ex) n=5
	[10 1 2 3 9]
	[8  4 5 6 7]
	=> 7 6 5 4 8 9 3 2 1 10
*/