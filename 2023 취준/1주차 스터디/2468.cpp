#include <bits/stdc++.h>
// 안전 영역

#define endl '\n'
#define MAX 100

using namespace std;
int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y, int water_height)
{
    visited[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if (!visited[nx][ny] && board[nx][ny] > water_height)
            {
                DFS(nx, ny, water_height);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int max_height = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= max_height; i++)
    {
        int cnt = 0;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (!visited[x][y] && board[x][y] > i)
                {
                    cnt++;
                    DFS(x, y, i);
                }
            }
        }
        ans = max(cnt, ans);
        memset(visited, 0, sizeof(visited));
    }

    cout << ans;
}

/*
    안전 영역
    1. 단지번호붙이기 (2667) 과 완전히 같은 문제라고 볼 수 있음
    2. 메모리 초기화를 반드시 할 것
    3. 문제를 꼼꼼히 읽자
*/