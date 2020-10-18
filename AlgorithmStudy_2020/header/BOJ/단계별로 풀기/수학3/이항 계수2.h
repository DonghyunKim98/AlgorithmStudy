#include <bits/stdc++.h>
//11051�� ����
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

	//nCr ���� n�� 1���� r�� 0���� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			//base case => nCn || nC0 �϶� ����
			if (i == j || j == 0) bionominal_arr[i][j] = 1;
			//ó������ 10007�� ���� �������� �����ϸ� long long ���� �ص� �ȴ�.
			else bionominal_arr[i][j] = (bionominal_arr[i - 1][j] + bionominal_arr[i - 1][j - 1]) %DIV_NUM;
		}
	}

	cout << bionominal_arr[N][K];
}

/*
	���� ������ ���� �ſ� Ŀ�����Ƿ� Recursion���δ� Time Over�� �߻��Ѵ�.
	=> DP�� Ǯ ��.
*/