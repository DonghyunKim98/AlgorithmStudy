#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int N;
string arr[MAX];
bool visited[MAX][MAX];
int normal_ans = 0, blindness_ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Normal_DFS(int py, int px, char c)
{
    visited[py][px] = true;

    for (int k = 0; k < 4; k++)
    {
        int ny = py + dy[k], nx = px + dx[k];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && arr[ny][nx] == c)
        {
            Normal_DFS(ny, nx, c);
        }
    }
}

void Blindness_DFS(int py, int px, char c)
{
    visited[py][px] = true;

    for (int k = 0; k < 4; k++)
    {
        int ny = py + dy[k], nx = px + dx[k];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx])
        {
            if (c == 'R' || c == 'G')
            {
                if (arr[ny][nx] == 'R' || arr[ny][nx] == 'G')
                    Blindness_DFS(ny, nx, c);
            }
            else
            {
                if (arr[ny][nx] == 'B')
                {
                    Blindness_DFS(ny, nx, c);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j])
            {
                continue;
            }
            normal_ans++;
            Normal_DFS(i, j, arr[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j])
            {
                continue;
            }
            blindness_ans++;
            Blindness_DFS(i, j, arr[i][j]);
        }
    }

    cout << normal_ans << ' ' << blindness_ans;
}