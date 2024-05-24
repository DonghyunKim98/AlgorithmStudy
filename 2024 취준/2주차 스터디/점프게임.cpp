#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int N, K;
int arr[2][MAX];
bool visited[2][MAX];

int dx[2] = {1, -1};

void BFS()
{
    queue<pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(0, 0), 0));

    visited[0][0] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> current_node = q.front();
        q.pop();

        pair<int, int> node_coordinate = current_node.first;
        int py = node_coordinate.first, px = node_coordinate.second;
        int count = current_node.second;

        for (int k = 0; k < 3; k++)
        {
            if (k == 2)
            {
                int ny = !py, nx = px + K;
                if (nx >= N)
                {
                    cout << "1";
                    exit(0);
                }
                // 이미 방문했다면 다시 방문 의미 없음
                if (nx >= 0 && nx > count && arr[ny][nx] && !visited[ny][nx])
                {

                    visited[ny][nx] = true;
                    q.push(make_pair(make_pair(ny, nx), count + 1));
                }
                continue;
            }

            int ny = py, nx = px + dx[k];
            if (nx >= N)
            {
                cout << "1";
                exit(0);
            }
            if (nx >= 0 && nx > count && arr[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push(make_pair(make_pair(ny, nx), count + 1));
            }
        }
    }
    cout << "0";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = s[j] - 48;
        }
    }

    BFS();
}

/*
    1. 역시 조건만 다 확실히 하면 푼다!
*/