#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 100 + 1;
const int division = 1000000007;
lli dp[MAX][MAX];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;

    //base case
    dp[1][1] = 1;
    for (int ypos = 1; ypos <= n; ypos++) {
        for (int xpos = 1; xpos <= m; xpos++) {
            if (dp[ypos][xpos] == -1) dp[ypos][xpos] = 0;
            else if (ypos == 1 && xpos == 1) continue;
            else dp[ypos][xpos] = (dp[ypos - 1][xpos]%division + dp[ypos][xpos - 1]%division)%division;
        }
    }
    return dp[n][m];
}

/*
    dp[i][j]=dp[i-1][j]+dp[i][j-1];
*/