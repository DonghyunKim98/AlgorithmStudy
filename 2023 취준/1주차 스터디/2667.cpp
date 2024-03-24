#include <bits/stdc++.h>

#define endl '\n'
#define MAX 25

using namespace std;

char board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;
int cnt = 0;
vector<int> vc;

void DFS(int x, int y)
{
    visited[x][y] = true, cnt++;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if (!visited[nx][ny] && board[nx][ny] == '1')
            {
                DFS(nx, ny);
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
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = s[j];
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (!visited[x][y] && board[x][y] == '1')
            {
                cnt = 0;
                DFS(x, y);
                vc.push_back(cnt);
            }
        }
    }

    sort(vc.begin(), vc.end());
    cout << vc.size() << endl;
    for (auto u : vc)
    {
        cout << u << endl;
    }
}

/*
    Tip 1번 : 아무 생각없이 무조건 int 로 선언하기 금지
    Tip 2번 : dx , dy 선언하기
*/