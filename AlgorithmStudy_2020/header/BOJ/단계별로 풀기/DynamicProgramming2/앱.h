#include <bits/stdc++.h>
//7579�� ����
using namespace std;
const int MAX = 10000 + 1;
int N, M;
vector<int> app(100);
vector<int> cost(100);
int dp[101][MAX];
void solution() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> app[i];

	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		total += cost[i];
	}

	int answer = INT_MAX;
	//dp 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 10000; j++) {
			//base case ����
			if (i == 0) {
				if (cost[0] <= j) dp[0][j] = app[0];
				continue;
			}
			//i��° item ������������ �ִ밪 
			//i��° cost�� j���� �۾ƾ� �ϴ� ������ �� ����.
			if (cost[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + app[i]);
			//i��° item ����X
			else
				dp[i][j] = dp[i - 1][j];

			//�ּ��� M�� Ȯ���������� ����� �ּڰ��� ��ȯ.
			//�ٵ� dp[i][j] == M �� �ϸ� Ʋ����.
			//M�� Ȯ���������� cost > M �ʰ��������� cost �� �� �ֳ�??
			//=> ���� dp[i][j]�� base case�� item��� ���� �� �ִ� ���ڵ�θ� �߾��⶧���� M�� �ʰ��� ���� �־���.
			//�� �־��� item���� ������ M�� ������ ���� �ֱ� ����!! 
			//ex) (10,20) ���� 15�� �������ݾ�!
			if (dp[i][j] >= M) {
				answer = min(answer, j);
			}
		}
	}
	cout << answer;
}

/*
	�˰��� �ؼ�
	=> 12865�� ���� ����
	=> DP[i][j] : i��° item���� ����Ҷ� j������� ���� �� �ִ� �ִ��� byte
	=> DP[i][j] = DP[i-1][j] (i��° item ���� X => cost�� j���� ŭ)
				= max(DP[i-1][j], DP[i-1][j-cost[i]] + app[i]) (i��° item ���� => cost�� j���� ����)

	�˰��� ����Ʈ
	-> �и� ó������ 12865�� ���� ����� ������� �����ߴµ� ������ �� ������...
	-> i�� item���� �߻��� �� ������ j�� cost�� �ƴ� memory�� �����߱� ����.
	-> �� �������� ������ �и� 3���� (item,cost,memory)
	-> � ���� ����������, � ���� ���Ӻ����� �� ������ ����� ������ ���� ��� �׾ư����Ѵ�.
	-> �׸��� 1�ʶ�� �͵� �и� ��Ʈ�����ٵ�.. 1��� ������ 1�ʴϱ�, ���⼭ 100*1000�� �̸� 10�ʰ� �ɸ�
	-> �и� Time over �� �ɸ� �ٴ� ���� �����ؾ� �ߴ�.

	* Base case ���������� �����ϰ� cost[0]�϶��� �ߴ�. -> �ٵ� �̷��� �Ǵ� ������ ����?

*/