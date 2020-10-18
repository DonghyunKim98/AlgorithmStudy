#include <bits/stdc++.h>
//10942�� ����
using namespace std;
const int MAX = 2000 + 1;
int arr[MAX];
bool dp[MAX][MAX];
void solution() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, false, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//base case ���� -> gap�� 0�϶��� 1�϶�.
	//why? �������� ������ ������ Ȧ��&¦�� ��������� ��.
	int gap = 0;
	for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
		dp[start_idx][start_idx + gap] = true;
	}
	gap = 1;
	for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
		if (arr[start_idx] == arr[start_idx + gap])
			dp[start_idx][start_idx + gap] = true;
	}

	//dp => ��ó��.
	for (gap = 2; gap <= N; gap++) {
		for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
			if (arr[start_idx] == arr[start_idx + gap])
				if (dp[start_idx + 1][start_idx + gap - 1] == true)
					dp[start_idx][start_idx + gap] = true;
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		if (dp[start][end]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}

/*
	an�� �߰��� �縰����� ������ �� �� ����. �� Ȧ����, ¦������ ���ε��� ������. 
	=> an-1�� ������ �̿��� �� ����. �ٸ� ����� �ʿ���.
	=> TLE �� ����.

	an�� ������ �縰����� ����.
	an�� ���� �縰����� ����.
	
	�˰��� ����Ʈ
	=> ���� ���� �����ʳ��� �������� ��� Ȯ���ϸ鼭 ���� ������ �ȴ�.
	=> dp[start][end] = true (dp[start-1][end-1]==true && arr[start]=arr[end])
	
	* �ᱹ �� 2���� �迭�̰� �ſ� ���� ���̵�� �ε� ���ø��� ���ߴ�. 
	  LCSó�� 1�������� �������� �ӹ����� ����.
	  �ѹ� �ô� 2���� dp�� idea��� ���� ���ø�����, ������ �Ǹ� �ƿ� ���Ѵٴ°� ������ ������ �ƽ���.
*/