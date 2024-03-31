#include <bits/stdc++.h>
#define MAX 1001
#define endl '\n'

using namespace std;

int N, M, H, W, F_r, F_c;
int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int start_px, int start_py)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(start_px, start_py), 0));
    visited[start_px][start_py] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> current_coor = q.front();
        q.pop();

        int px = current_coor.first.first, py = current_coor.first.second;
        int count = current_coor.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = px + dx[k], ny = py + dy[k];
            if (nx < 1 || nx > N || ny < 1 || ny > M || visited[nx][ny])
                continue;
            if (nx + H - 1 > N || ny + W - 1 > M)
                continue;

            bool flag = false;
            // 양 세로 줄 검사
            for (int i = 0; i < H; i++)
            {
                int n_nx = nx + i, n_ny = ny;
                if (board[n_nx][n_ny])
                {
                    flag = true;
                    break;
                }

                n_ny = ny + W - 1;
                if (board[n_nx][n_ny])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;

            // 양 가로 줄 검사
            for (int i = 0; i < W; i++)
            {
                int n_nx = nx, n_ny = ny + i;
                if (board[n_nx][n_ny])
                {
                    flag = true;
                    break;
                }
                n_nx = nx + H - 1;
                if (board[n_nx][n_ny])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;

            // 탈출
            if (nx == F_r && ny == F_c)
            {

                cout << count + 1;
                return;
            }

            visited[nx][ny] = true;
            q.push(make_pair(make_pair(nx, ny), count + 1));
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= M; y++)
        {
            cin >> board[x][y];
        }
    }
    int S_r, S_c;

    cin >> H >> W >> S_r >> S_c >> F_r >> F_c;

    BFS(S_r, S_c);
}