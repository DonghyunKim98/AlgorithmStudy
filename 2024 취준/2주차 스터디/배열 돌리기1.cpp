#include <bits/stdc++.h>
#define MAX 300

using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int N, M, R;
// 오, 아, 왼, 위
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void rotate(int box)
{

    for (int i = 0; i < box; i++)
    {                             // 박스수만큼 반복(1칸 전진)(시작점은 start, start+1, start+2..)
        int startVal = arr[i][i]; // 각 박스 시작은 [0][0] -> [1][1] -> [2][2]...
        int r = i;
        int c = i;

        int k = 0;
        while (k < 4)
        {

            int nr = r + dr[k]; // arr[nr][nc]는 옮길 대상임 (arr[r][c]로 옮겨야 함)
            int nc = c + dc[k];

            if (nr == i && nc == i)
                break;
            if (i <= nr && nr < N - i && i <= nc && nc < M - i)
            {

                // 차례로 시계 반대방향으로 옮김
                arr[r][c] = arr[nr][nc];
                r = nr;
                c = nc;
            }
            else
            { // 다음에 옮길 칸이 배열 범위 넘어가버리면 해당 라인은 다 옮긴거라서 k 증가
                k++;
            }
        }
        arr[i + 1][i] = startVal; // 처음에 시작지점 빼놨던거 마지막에 빈 자리에 넣어줌.
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = min(N, M) / 2;

    for (int i = 0; i < R; i++)
    {
        rotate(cnt);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}