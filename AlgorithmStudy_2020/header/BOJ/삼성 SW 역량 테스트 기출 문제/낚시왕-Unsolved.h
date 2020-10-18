#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
#define MAX 100 + 1
using namespace std;

struct Shark_Info
{
    int R;
    int C;
    int Speed;
    int Direct;
    int Size;
    int Num;
};

int R, C, M, Answer;
vector<int> MAP[MAX][MAX];
vector<Shark_Info> Shark;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

bool Standard(int A, int B)
{
    if (Shark[A].Size > Shark[B].Size) return true;
    return false;
}

void Input()
{
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark.push_back({ r,c,s,d,z,i });
        MAP[r][c].push_back(i);
    }
}

bool Check()
{
    for (int i = 0; i < Shark.size(); i++)
    {
        if (Shark[i].Size != 0) return false;
    }
    return true;
}

void Fishing(int Idx)
{
    for (int i = 1; i <= R; i++)
    {
        if (MAP[i][Idx].size() != 0)
        {
            Answer = Answer + Shark[MAP[i][Idx][0]].Size;
            Shark[MAP[i][Idx][0]].Size = 0;
            MAP[i][Idx].clear();
            break;
        }
    }
}

void Move_Shark()
{
    for (int i = 0; i < Shark.size(); i++)
    {
        if (Shark[i].Size == 0) continue;
        int x = Shark[i].R;
        int y = Shark[i].C;
        MAP[x][y].clear();
    }

    for (int i = 0; i < Shark.size(); i++)
    {
        if (Shark[i].Size == 0) continue;
        int x = Shark[i].R;
        int y = Shark[i].C;
        int Direct = Shark[i].Direct;
        int Speed = Shark[i].Speed;

        if (Direct == 1 || Direct == 2)
        {
            int Rotate = (R - 1) * 2;
            if (Speed >= Rotate) Speed = Speed % Rotate;

            for (int j = 0; j < Speed; j++)
            {
                int nx = x + dx[Direct];
                int ny = y + dy[Direct];
                if (nx < 1)
                {
                    Direct = 2;
                    nx = nx + 2;
                }
                if (nx > R)
                {
                    Direct = 1;
                    nx = nx - 2;
                }
                x = nx;
                y = ny;
            }
        }
        else
        {
            int Rotate = (C - 1) * 2;
            if (Speed >= Rotate) Speed = Speed % Rotate;

            for (int j = 0; j < Speed; j++)
            {
                int nx = x + dx[Direct];
                int ny = y + dy[Direct];
                if (ny < 1)
                {
                    Direct = 3;
                    ny = ny + 2;
                }
                if (ny > C)
                {
                    Direct = 4;
                    ny = ny - 2;
                }
                x = nx;
                y = ny;
            }
        }

        Shark[i].R = x;
        Shark[i].C = y;
        Shark[i].Direct = Direct;
        MAP[x][y].push_back(i);
    }
}

void Kill_Shark()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (MAP[i][j].size() > 1)
            {
                sort(MAP[i][j].begin(), MAP[i][j].end(), Standard);
                int Live_Index = MAP[i][j][0];
                for (int k = 1; k < MAP[i][j].size(); k++)
                {
                    Shark[MAP[i][j][k]].Size = 0;
                    Shark[MAP[i][j][k]].R = -1;
                    Shark[MAP[i][j][k]].C = -1;
                }
                MAP[i][j].clear();
                MAP[i][j].push_back(Shark[Live_Index].Num);
            }
        }
    }
}

void Solution()
{
    if (M == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= C; i++)
    {
        if (Check() == true) break;
        Fishing(i);
        Move_Shark();
        Kill_Shark();
    }
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}
