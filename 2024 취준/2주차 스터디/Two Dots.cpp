#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int N, M;
int startX, startY;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[MAX][MAX];
string board[MAX];

void DFS(int px, int py, int depth)
{
    if (px == startX && py == startY && depth >= 4)
    {
        cout << "Yes";
        exit(0);
    }

    for (int k = 0; k < 4; k++)
    {
        int nx = px + dx[k], ny = py + dy[k];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || board[nx][ny] != board[px][py])
            continue;

        visited[nx][ny] = true;
        DFS(nx, ny, depth + 1);
        visited[nx][ny] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        board[i] = s;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j])
                continue;

            startX = i, startY = j;
            DFS(i, j, 0);
        }
    }

    cout << "No";
}