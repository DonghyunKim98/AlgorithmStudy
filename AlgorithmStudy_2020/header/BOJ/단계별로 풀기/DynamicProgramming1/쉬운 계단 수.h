#include <bits/stdc++.h>
//10844번 문제
using namespace std;
const long long MAX = 1000000000;
void EasyStair() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	//Memoization -> 맨 마지막 자리수의 값
	long long arr[101][10];
	//base case
	arr[1][0] = 0;
	for (int i = 1; i <= 9; i++) arr[1][i] = 1;
	//DP
	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[i - 1][1]%MAX;
		for(int j=1;j<=8;j++)
			arr[i][j] = (arr[i - 1][j-1]%MAX + arr[i - 1][j+1]%MAX)%MAX;
		arr[i][9] = arr[i - 1][8]%MAX;
	}
	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += arr[N][i];
		total %= MAX;
	}
	cout << total;
}