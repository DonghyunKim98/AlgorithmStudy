#include <bits/stdc++.h>
//11054번 문제
using namespace std;

void LVS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	int vitonic = 0;

	//input
	cin >> N;
	int* lengthUP = new int[N];
	int* lengthDown = new int[N];
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//오름차순 찾기
	for (int i = 0; i < N; i++) {
		lengthUP[i] = 1;
		for (int k = 0; k < i; k++) {
			if (arr[k] < arr[i])
				lengthUP[i] = max(lengthUP[i], lengthUP[k] + 1);
		}
	}
	//내림차순 찾기
	for (int i = N - 1; i >= 0; i--) {
		lengthDown[i] = 1;
		for (int k = i + 1; k < N; k++) {
			if (arr[k] < arr[i])
				lengthDown[i] = max(lengthDown[i], lengthDown[k] + 1);
		}
		//오름차순+내림차순이 큰 것을 찾기
		vitonic = max(lengthDown[i] + lengthUP[i], vitonic);
	}
	cout << vitonic-1;
}