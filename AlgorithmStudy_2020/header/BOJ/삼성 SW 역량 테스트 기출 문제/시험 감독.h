#include <bits/stdc++.h>
//13458번 문제
using namespace std;
const int MAX = 1000000 + 1;
int N;
int B, C;
int arr[MAX];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> B >> C;
	long long answer = 0;
	for (int i = 1; i <= N; i++) {
		//총 감독관
		answer ++;
		arr[i] -= B;
		//부감독관
		if (arr[i] > 0) {
			if (arr[i] % C == 0) answer += arr[i] / C;
			else answer += arr[i] / C + 1;
		}
	}
	cout << answer;
}