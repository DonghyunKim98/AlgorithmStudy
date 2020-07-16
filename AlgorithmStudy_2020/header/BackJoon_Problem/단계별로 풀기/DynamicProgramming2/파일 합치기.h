#include <bits/stdc++.h>
//11066�� ����
//https://js1jj2sk3.tistory.com/search/11066 ����
using namespace std;
const int MAX = 500 + 1;
int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];


void FileMerge() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		for (int gap = 1; gap < K; gap++) {
			for (int tx = 1; tx + gap <= K; tx++) {
				int ty = tx + gap;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; mid++) {
					//tx~ty ������ �κ����� �������� ���ϴ� ������
					//[tx,mid] ������ ���� [mid+1][ty] ������ ����� ���� ���� �� tx~ty�� �κ����̱� ����.
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
		T--;
	}
}

/*
	�˰��� ����Ʈ
	1. �ϴ� �⺻������ '����' '��' �� �������� �ϴ� 2���� dp �迭�� ����. �� ���� ì�ܵ���.(�Ӹ���ҵ� ���� ����)
	2. gap�� �������� ���� �÷����� dp ����. ���ݸ� �����ϸ� ��� �̰͵� ���ø��� ����� O(n^3)�ΰ� ����������.
	3. O(n^2)�� ������, �����غ���.
*/