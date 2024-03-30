#include <bits/stdc++.h>

#define endl '\n'
#define MAX 10

using namespace std;

int N;
char original_board[MAX][MAX];
char open_board[MAX][MAX];
char ans_board[MAX][MAX];

int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            original_board[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            open_board[i][j] = s[j];
        }
    }

    // 정답 보드 채우기
    bool flag = false; // 지뢰가 있는 칸을 열었는지 여부
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (open_board[x][y] == '.')
            {
                ans_board[x][y] = '.';
                continue;
            }
            if (original_board[x][y] == '*')
            {
                flag = true;
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (original_board[nx][ny] == '*')
                    {
                        cnt++;
                    }
                }
            }
            ans_board[x][y] = (char)(cnt + 48);
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (flag && original_board[x][y] == '*')
            {
                cout << '*';
            }
            else
            {
                cout << ans_board[x][y];
            }
        }
        cout << endl;
    }
}

/*
  Tip
    (1) : and 로 이뤄진 조건문을 쓸때 앞쪽에서 false 면 뒤를 검사하지 않는 걸 이용하자
    (2) : int 에서 char 변형 (48 빼기)
 */