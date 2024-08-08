#include <bits/stdc++.h>
#define MAX 51

using namespace std;

typedef pair<int, int> pii;

int N, L, R;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void printArr()
{
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int ans = 0;

    while (true)
    {
        // printArr();

        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (0 <= ny && ny < N && 0 <= nx && nx < N)
                    {
                        // 아직 이동할 수 있음
                        if (L <= abs(arr[i][j] - arr[ny][nx]) && abs(arr[i][j] - arr[ny][nx]) <= R)
                        {
                            flag = false;
                        }
                    }
                }
            }
        }

        if (flag)
        {
            cout << ans;
            return 0;
        }

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j])
                    continue;

                int total = 0;
                vector<pii> vc;
                queue<pii> q;

                q.push({i, j});
                vc.push_back({i, j});
                total += arr[i][j];

                while (!q.empty())
                {
                    int py = q.front().first;
                    int px = q.front().second;
                    visited[py][px] = true;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = py + dy[k];
                        int nx = px + dx[k];

                        if (0 <= ny && ny < N && 0 <= nx && nx < N && !visited[ny][nx])
                        {

                            // cout << ny << ' ' << nx << endl;

                            if (L <= abs(arr[py][px] - arr[ny][nx]) && abs(arr[py][px] - arr[ny][nx]) <= R)
                            {

                                total += arr[ny][nx];
                                vc.push_back({ny, nx});
                                q.push({ny, nx});
                            }
                        }
                    }
                }

                // cout << "total : " << total << endl;
                for (auto u : vc)
                {
                    int py = u.first;
                    int px = u.second;

                    arr[py][px] = total / vc.size();
                }
            }
        ans++;
    }
}