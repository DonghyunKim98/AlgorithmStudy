#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
int board[100][100];
bool original_viruses[100][100];
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void reset_board()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (!original_viruses[x][y] && board[x][y] == 2)
                board[x][y] = 0;
        }
    }
}

void virus_BFS()
{
    queue<pair<int, int>> q;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (original_viruses[x][y])
                q.push({x, y});
        }
    }

    while (!q.empty())
    {
        int px = q.front().first, py = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = px + dx[k], ny = py + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // 바이러스나 벽이 있으면 못감
            if (board[nx][ny])
                continue;

            board[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    int temp = 0;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (board[x][y] == 0)
                temp++;
        }
    }

    ans = max(temp, ans);
}
int temp1 = 1;
void chose_DFS(int n, int k)
{
    if (k == 3)
    {
        virus_BFS();
        reset_board();
        return;
    }

    for (int startX = 0; startX < N; startX++)
    {
        for (int startY = 0; startY < M; startY++)
        {

            if (!board[startX][startY])
            {
                board[startX][startY] = 1;
                chose_DFS(startX * M + startY, k + 1);
                board[startX][startY] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
                original_viruses[i][j] = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!board[i][j])
            {
                board[i][j] = 1;
                chose_DFS(i * N + j, 1);
                board[i][j] = 0;
            }
        }
    }

    cout << ans;
}

/*
    실수 1번 : N 과 M 인데, 아무 생각없이 스도쿠 처럼 N*N 이라 착각해버린 것
    해야할 것 : 이거 그대로 해도 되는거 맞나?
*/