#include <bits/stdc++.h>

using namespace std;

void Longest_Increasing_Subsequence() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << "몇개의 원소가 있습니까?:";
	int N;
	cin >> N;
	int* arr = new int[N];
	cout << "원소를 입력하세요\n";
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	//Memoization 및 점화식의 핵심 배열
	int* length = new int[N];
	/*
	// O(n^2) 반복문
	for (int k = 0; k < N; k++) {
		//오직 그 index만을 포함하는 경우
		length[k] = 1;
		for (int i = 0; i < k; i++) {
				if (arr[k] > arr[i]) {
					length[k] = max(length[k], length[i] + 1);
				}
		}
	}
	*/
	int Max=0;
	for (int i = 0; i < N; i++) {
		Max = max(Max, length[i]);
	}
	cout << "최장 부분 수열의 길이는 " << Max << "입니다" << endl;
}