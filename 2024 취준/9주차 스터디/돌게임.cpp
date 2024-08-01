#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    int dp[1001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);

    if (dp[N] % 2)
        cout << "SK";
    else
        cout << "CY";
}

// DP[N] = min ( (DP[N - 1] + 1의 경우) OR (DP[N - 3] + 1의 경우) )