#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int N, arr[MAX][MAX];
int answer_white = 0, answer_blue = 0;

void divConq(int start_x, int start_y, int end_x, int end_y)
{
    int start_color = arr[start_x][start_y];

    for (int i = start_x; i < end_x; i++)
    {
        for (int j = start_y; j < end_y; j++)
        {
            // 시작 색깔과 다름 -> 시작 색깔로 색종이를 만들 수가 없음
            if (start_color != arr[i][j])
            {
                divConq(start_x, start_y, (start_x + end_x) / 2, (start_y + end_y) / 2);
                divConq((start_x + end_x) / 2, start_y, end_x, (start_y + end_y) / 2);
                divConq(start_x, (start_y + end_y) / 2, (start_x + end_x) / 2, end_y);
                divConq((start_x + end_x) / 2, (start_y + end_y) / 2, end_x, end_y);
                return;
            }
        }
    }

    if (start_color == 0)
        answer_white++;
    else
        answer_blue++;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    divConq(0, 0, N, N);

    cout << answer_white << '\n';
    cout << answer_blue << '\n';
}