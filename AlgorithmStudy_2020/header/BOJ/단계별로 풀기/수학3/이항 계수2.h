#include <bits/stdc++.h>
//11051번 문제
using namespace std;
const int MAX = 1000 + 1;
const int DIV_NUM = 10007;
//memoizaiton
int bionominal_arr[MAX][MAX] = { 0 };


void Binominal() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	//nCr 에서 n은 1부터 r은 0부터 시작
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			//base case => nCn || nC0 일때 설정
			if (i == j || j == 0) bionominal_arr[i][j] = 1;
			//처음부터 10007로 나눈 나머지로 저장하면 long long 으로 해도 된다.
			else bionominal_arr[i][j] = (bionominal_arr[i - 1][j] + bionominal_arr[i - 1][j - 1]) %DIV_NUM;
		}
	}

	cout << bionominal_arr[N][K];
}

/*
	이제 들어오는 값이 매우 커졌으므로 Recursion으로는 Time Over가 발생한다.
	=> DP로 풀 것.
*/