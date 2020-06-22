#include <bits/stdc++.h>
//1463¹ø ¹®Á¦
using namespace std;
const int MAX = 1000000 + 1;
void MakingOne() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int cnt = 0;
	//Memoization
	int* arr = new int[MAX];
	//base case
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	if (N > 3) {
		for (int i = 4; i <= N; i++) {
			arr[i] = min(min(arr[i / 3] + (i % 3)+1, arr[i / 2] + (i % 2)+1), arr[i - 1] + 1);
		}
	}
	cout << arr[N];
}

