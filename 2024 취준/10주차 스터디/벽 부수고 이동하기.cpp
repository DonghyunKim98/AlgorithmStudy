#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef pair<int, int> pii;

int N, M;
int arr[MAX][MAX];
int visited[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 입력 받기
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < M; j++)
        {
            arr[i][j] = temp[j] - '0'; // 맵 초기화
        }
    }

    // BFS를 위한 큐 초기화
    queue<pair<pii, int>> q;
    q.push({{0, 0}, 1});  // (0, 0)에서 시작, 벽을 부술 수 있는 기회 1회
    visited[0][0][1] = 1; // 시작 지점 방문 처리 및 거리 1로 설정

    while (!q.empty())
    {
        int py = q.front().first.first;
        int px = q.front().first.second;
        int block = q.front().second;
        q.pop();

        // 목적지에 도달한 경우
        if (py == N - 1 && px == M - 1)
        {
            cout << visited[py][px][block];
            return 0;
        }

        // 네 방향으로 이동 시도
        for (int k = 0; k < 4; k++)
        {
            int ny = py + dy[k];
            int nx = px + dx[k];

            if (0 <= ny && ny < N && 0 <= nx && nx < M)
            {
                // 이동할 수 있는 칸
                if (arr[ny][nx] == 0 && visited[ny][nx][block] == 0)
                {
                    visited[ny][nx][block] = visited[py][px][block] + 1;
                    q.push({{ny, nx}, block});
                }

                // 벽을 부수고 이동할 수 있는 경우
                else if (arr[ny][nx] == 1 && block == 1 && visited[ny][nx][0] == 0)
                {
                    visited[ny][nx][0] = visited[py][px][block] + 1;
                    q.push({{ny, nx}, 0});
                }
            }
        }
    }

    // 경로를 찾지 못한 경우
    cout << "-1";
    return 0;
}
