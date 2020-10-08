#include <bits/stdc++.h>
//16639번 문제
using namespace std;
const int MAX = 20;
string s;
int N, ans=0;
//[i,j] 범위 내 연산 최댓값, 최솟값
int maxCache[MAX][MAX];
int minCache[MAX][MAX];

void DFS() {

}

int cal(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> s;
	for (int i = 0; i < MAX / 2; i++) {
		for (int j = 0; j < MAX / 2; j++) {
			maxCache[i][j] = INT_MIN;
			minCache[i][j] = INT_MAX;
		}
	}
	int numCnt = N / 2 + 1;
	//[i,i]사이의 최댓값과 최솟값은 자기자신
	for (int i = 0; i < numCnt; i++) {
		maxCache[i][i] = minCache[i][i] = s[i * 2] - '0';
	}
	//cnt->계산할 숫자의 개수
	for (int cnt = 1; cnt < numCnt; cnt++) {
		//idx->계산할 숫자의 첫 위치
		for (int idx = 0; idx < numCnt - cnt; idx++) {
			//[idx,idx+i-1],[idx+1,idx+cnt] 의 값을 계산
			for (int i = 1, j = cnt; i <= cnt; i++, j--) {
				int opIdx = (idx + cnt - j) * 2 + 1; //이 계산식이 복잡해서 j를 넣은것같다
				char op = s[opIdx];
				int candidates[4] = {
					cal(maxCache[idx][idx + i -1],maxCache[idx + i][idx + cnt],op),
					cal(maxCache[idx][idx + i -1],minCache[idx + i][idx + cnt],op),
					cal(minCache[idx][idx + i -1],maxCache[idx + i][idx + cnt],op),
					cal(minCache[idx][idx + i -1],minCache[idx + i][idx + cnt],op)
				};
				sort(candidates, candidates + 4);
				maxCache[idx][idx + cnt] = max(maxCache[idx][idx + cnt], candidates[3]);
				minCache[idx][idx + cnt] = min(minCache[idx][idx + cnt], candidates[0]);
			}
		}
	}
	int result = maxCache[0][numCnt - 1];
	cout << result;
}

/*
	끔찍한 DP문제..
	펠레드롬문제랑 비슷하긴한데 너무 어렵다
*/