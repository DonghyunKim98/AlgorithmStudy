// 토마토
#include <bits/stdc++.h>

#define MAX 1000
#define endl '\n'

using namespace std;
typedef pair<int, int> pii;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> M >> N;
    queue<pii> q;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> board[x][y];
            if (board[x][y] == 1)
            {
                q.push(make_pair(x, y));
            }
        }
    }

    while (true)
    {
        if (q.empty())
            break;
        pair<int, int> current_node = q.front();
        q.pop();
        int px = current_node.first, py = current_node.second;
        visited[px][py] = true;

        for (int k = 0; k < 4; k++)
        {
            int nx = dx[k] + px;
            int ny = dy[k] + py;

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (!visited[nx][ny] && board[nx][ny] == 0)
                {
                    board[nx][ny] = board[px][py] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (board[x][y] == 0)
            {
                cout << -1;
                return 0;
            }
            ans = max(board[x][y], ans);
        }
    }
    cout << ans - 1;
    return 0;
}

/*
    Tip (1) : BFS 로만 풀어야 한다는 것을 확실히 인지
    Tip (2) : 익으면 숫자가 올라감
*/