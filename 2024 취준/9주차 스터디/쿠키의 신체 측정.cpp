#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001

using namespace std;

char arr[MAX][MAX];
int N, heart_x_pos, heart_y_pos;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void find_heart()
{
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || i == N - 1)
            continue;
        for (int j = 0; j < N; j++)
        {
            if (j == 0 || j == N - 1)
                continue;

            bool flag = true;
            for (int k = 0; k < 4; k++)
            {
                int nx = dx[k] + i, ny = dy[k] + j;

                if (arr[nx][ny] == '_')
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                heart_x_pos = i, heart_y_pos = j;
                return;
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
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    // 심장 찾기
    find_heart();

    int left_hand_cnt = 0, right_hand_cnt = 0, body_cnt = 0, left_leg_cnt = 0, right_leg_cnt = 0;
    // 왼쪽 팔
    for (int j = heart_y_pos - 1; j >= 0; j--)
    {
        if (arr[heart_x_pos][j] == '*')
            left_hand_cnt++;
        else
            break;
    }

    // 오른쪽 팔
    for (int j = heart_y_pos + 1; j < N; j++)
    {
        if (arr[heart_x_pos][j] == '*')
            right_hand_cnt++;
        else
            break;
    }

    // 허리
    for (int i = heart_x_pos + 1; i < N; i++)
    {
        if (arr[i][heart_y_pos] == '*')
            body_cnt++;
        else
            break;
    }

    // 왼쪽 다리
    for (int i = heart_x_pos + 1 + body_cnt; i < N; i++)
    {
        if (arr[i][heart_y_pos - 1] == '*')
            left_leg_cnt++;
        else
            break;
    }

    // 왼쪽 다리
    for (int i = heart_x_pos + 1 + body_cnt; i < N; i++)
    {
        if (arr[i][heart_y_pos + 1] == '*')
            right_leg_cnt++;
        else
            break;
    }

    // 행렬은 [1,1]부터 시작함
    cout << heart_x_pos + 1 << ' ' << heart_y_pos + 1 << endl;

    cout << left_hand_cnt << ' ' << right_hand_cnt << ' ' << body_cnt << ' ' << left_leg_cnt << ' ' << right_leg_cnt;
}
