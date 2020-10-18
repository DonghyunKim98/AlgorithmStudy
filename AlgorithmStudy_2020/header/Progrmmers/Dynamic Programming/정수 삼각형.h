#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	//memoization
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
	//base case 
	dp[0][0] = triangle[0][0];
	//dynamic programming
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			//ù�� ���� ó��
			if (j == 0) dp[i][0]=(dp[i - 1][0] + triangle[i][0]);
			//���� ���� ó��
			else if (j == triangle[i].size() - 1) dp[i][j]=(dp[i - 1][j - 1] + triangle[i][j]);
			else dp[i][j]=(max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]);
			if (i == triangle.size() - 1) answer = max(dp[i][j], answer);
		}
	}
	return answer;
}

/*
	���� ���� ������ �Ҷ��� ���!! ù��°���� ��ü ������ ũ��, �ι�°�� ������ ���Ͱ� �󸶳� �Ҵ����.
*/