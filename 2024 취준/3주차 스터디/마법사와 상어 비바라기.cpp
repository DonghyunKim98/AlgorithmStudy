#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M, d;
int board[100][100];
bool moved_cloud[100][100];
vector<pair<int, int>> cloud;
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void print_board()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cout << board[x][y] << ' ';
        }
        cout << endl;
    }
}

void init_cloud()
{
    cloud.push_back({N - 1, 0});
    cloud.push_back({N - 1, 1});
    cloud.push_back({N - 2, 0});
    cloud.push_back({N - 2, 1});
}

pair<int, int> calculate_nx_ny(int nx, int ny)
{
    if (nx < 0)
    {
        if (abs(nx) % N == 0)
            nx = 0;
        else
            nx = N - (abs(nx) % N);
    }
    else if (nx >= N)
    {
        nx = nx % N;
    }
    if (ny < 0)
    {
        if (abs(ny) % N == 0)
            ny = 0;
        else
            ny = N - (abs(ny) % N);
    }
    else if (ny >= N)
    {
        ny = ny % N;
    }

    return {nx, ny};
}

// 모든 구름이 di 방향으로 si칸 이동한다.
void step1(int s)
{
    for (auto c : cloud)
    {
        int px = c.first, py = c.second;
        int nx = px + dx[d] * s, ny = py + dy[d] * s;

        pair<int, int> coord = calculate_nx_ny(nx, ny);

        moved_cloud[coord.first][coord.second] = true;
    }
    cloud.clear();
}

void step2()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            // 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
            if (moved_cloud[x][y])
                board[x][y]++;
        }
    }
}

void step4()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (moved_cloud[x][y])
            {
                // 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼
                // (r, c)에 있는 바구니의 물이 양이 증가한다.
                int temp = 0;
                for (int k = 1; k < 9; k += 2)
                {
                    int nx = x + dx[k], ny = y + dy[k];

                    // 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;

                    if (board[nx][ny])
                        temp++;
                }
                board[x][y] += temp;
            }
        }
    }
}

void step5()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
            // 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
            if (board[x][y] >= 2 && !moved_cloud[x][y])
            {
                cloud.push_back({x, y});
                board[x][y] -= 2;
            }
        }
    }

    memset(moved_cloud, false, sizeof(moved_cloud));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    init_cloud();

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> board[x][y];
        }
    }

    int s;
    for (int i = 0; i < M; i++)
    {
        cin >> d >> s;
        d--;
        step1(s);
        step2();
        step4();
        step5();
    }

    // print_board();

    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            ans += board[x][y];
        }
    }

    cout << ans;
}

/*
    실수 1. step2 와 step4 를 구분하지 않은 것
    실수 2. 구름이 이동했을때 단순하게 한 사이클(?)만 넘어간다고 착각한 것
*/