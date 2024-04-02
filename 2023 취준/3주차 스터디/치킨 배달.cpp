#include <bits/stdc++.h>

#define endl '\n'
#define MAX 10000

using namespace std;

typedef vector<pair<int, int>> vii;

int board[MAX][MAX], N, M, ans = MAX;
vii house, chicken, chosen;

void calculate_ans()
{
    int ret = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int temp = MAX;
        for (int j = 0; j < chosen.size(); j++)
        {
            temp = min((abs(house.at(i).first - chosen.at(j).first) + abs(house.at(i).second - chosen.at(j).second)), temp);
        }
        ret += temp;
    }
    ans = min(ret, ans);
}

void DFS(int k, int depth) // k와 depth 를  다 설정하는 것이 중요
{
    if (depth == M)
    {
        calculate_ans();
        return;
    }

    for (int i = k; i < chicken.size(); i++)
    {
        chosen.push_back(chicken[i]);
        DFS(i + 1, depth + 1); // 시간을 줄이기 위해 여기가 필수적
        chosen.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
                house.push_back({i, j});

            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    DFS(0, 0);

    cout << ans;
}