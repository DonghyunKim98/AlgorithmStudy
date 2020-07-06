#include <bits/stdc++.h>
//9251�� ����
using namespace std;

void LCS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int dp[1001][1001], i, j;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			//���ؼ� ���ٸ� ��Ļ��� ���� �� (���� index�� �ش��ϴ� 2���� ���ڰ� �߰����� �ʾҴ�) +1
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			//���ؼ� �ٸ��ٸ�, ��Ļ��� �����̳� ������ ���� MAX��.
			else dp[i][j] = max(dp[i][j - 1], dp[i][j - 1]);

		}
	}
	cout << dp[s1.size()][s2.size()];
}


/*
	�˰��� ����
	1. String1[n], String2[k]�� ���ٸ� : [n, k] == [n-1, k-1] + 1
	=> �� ���ؼ� ���ٸ� String1[n] �� String2[k]�� �� �� �������� ���� ���¿��� +1
	=> �ƿ� 2���� ��� ����ϸ� �� �� (2���� ��� ����ֱ� ����)
	=> �ٵ� ��� �����غ��� [n-1,k] +1  or [n,k-1]+1 �ص� ��
	2. String1[n], String2[k]�� �ٸ��� : [n, k] == [n-1, k]�� [n, k-1] �� ū ��
	=> �� ���ؼ� ���� �ʴٸ� String1[n]�� �����ų�, String2[k]�� ���� ���¿��� ū ��.
	=> String1[n]�� String[k]�� �̿��ؼ� ���� ���� ������ ���� �����Ƿ�!! �� �� ������� ���� ���� +1�� �ϸ� �ȵ�.
*/