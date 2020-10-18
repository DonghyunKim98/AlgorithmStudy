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
			//첫항 예외 처리
			if (j == 0) dp[i][0]=(dp[i - 1][0] + triangle[i][0]);
			//끝항 예외 처리
			else if (j == triangle[i].size() - 1) dp[i][j]=(dp[i - 1][j - 1] + triangle[i][j]);
			else dp[i][j]=(max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]);
			if (i == triangle.size() - 1) answer = max(dp[i][j], answer);
		}
	}
	return answer;
}

/*
	이중 백터 선언을 할때의 방법!! 첫번째에는 전체 백터의 크기, 두번째엔 각각의 백터가 얼마나 할당될지.
*/