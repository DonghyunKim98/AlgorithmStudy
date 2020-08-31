#include <bits/stdc++.h>
//14501번 문제
using namespace std;
const int MAX = 15 + 1;
int Time[MAX], Price[MAX];
int N, ans=0;

void DFS(int idx,int temp_ret) {
	if (idx == N+1) {
		ans = max(ans, temp_ret);
		return;
	}
	//idx번째 선택안함
	DFS(idx + 1, temp_ret);
	//idx번째 선택
	if(idx+Time[idx]<=N+1)	DFS(idx + Time[idx], temp_ret + Price[idx]);
}



void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Time[i];
		cin >> Price[i];
	}
	DFS(1,0);
	cout << ans;
}

/*
	시간복잡도 -> O(2^n) (근데 n의 최대값이 고작 15)
*/