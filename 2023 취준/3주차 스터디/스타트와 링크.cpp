#include <bits/stdc++.h>
#define MAX 10000
#define endl '\n'

using namespace std;

int N;
int board[MAX][MAX];
vector<int> adj1;
bool visited[MAX];
int ans = MAX;

void calculate_diff()
{
    vector<int> adj2;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            adj2.push_back(i);
        }
    }

    int team1 = 0, team2 = 0;
    for (int i = 0; i < adj1.size(); i++)
    {
        for (int j = i + 1; j < adj1.size(); j++)
        {

            team1 += (board[adj1[i]][adj1[j]] + board[adj1[j]][adj1[i]]);
            team2 += (board[adj2[i]][adj2[j]] + board[adj2[j]][adj2[i]]);
        }
    }

    ans = min(ans, abs(team1 - team2));
}

void DFS(int k)
{
    if (k == N / 2)
    {
        calculate_diff();
        return;
    }
    for (int i = 0; i < N; i++)
    {

        if (!adj1.empty() && adj1.back() > i)
            continue;
        if (!visited[i])
        {
            visited[i] = true;
            adj1.push_back(i);
            DFS(k + 1);
            visited[i] = false;
            adj1.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    DFS(0);

    cout << ans;
}