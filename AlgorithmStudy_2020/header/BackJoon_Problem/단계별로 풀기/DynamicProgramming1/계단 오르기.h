#include <bits/stdc++.h>
//2579번 문제
using namespace std;

void ClimbingStairs() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	//0 -> 이 칸을 2칸 건너서 왔음! 
	//1 -> 이 칸을 1칸 건너서 왔음!
	long long arr[301][2];
	for (int i = 1; i <= N; i++) {
		long long score;
		cin >> score;
		//base case
		if (i == 1) {
			arr[1][0] = 0;
			arr[1][1] = score;
		}
		else if (i == 2) {
			arr[2][0] = score;
			//맨 처음에만 한해서 1칸->1칸 가능
			arr[2][1] = score + arr[1][1];
		}
		//DP
		else {
			arr[i][0] = score + max(arr[i - 2][0], arr[i - 2][1]);
			arr[i][1] = score + arr[i - 1][0];
		}
	}
	cout << max(arr[N][0], arr[N][1]);
}
