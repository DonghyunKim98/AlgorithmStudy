#include <bits/stdc++.h>

#define MAX 19
using namespace std;

char graph[MAX][MAX];
int moving[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
bool visited[MAX][MAX][4][2];

char dfs(int r, int c, int dir, char color, int cnt)
{
    visited[r][c][dir][color - '1'] = true;
    int nR = r + moving[dir][0];
    int nC = c + moving[dir][1];
    if (nR < 0 || nR >= MAX || nC < 0 || nC >= MAX || graph[nR][nC] != color)
    {
        if (cnt == 5)
        {
            return color;
        }
        else
        {
            return '0';
        }
    }
    return dfs(nR, nC, dir, color, cnt + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (graph[j][i] != '0')
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    if (visited[j][i][dir][graph[j][i] - '1'])
                        continue;
                    if (dfs(j, i, dir, graph[j][i], 1) != '0')
                    {
                        cout << graph[j][i] << '\n'
                             << j + 1 << ' ' << i + 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}