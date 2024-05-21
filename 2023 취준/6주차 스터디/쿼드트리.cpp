#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int N;
char arr[MAX][MAX];
vector<char> ans;

void divConq(int startX, int startY, int endX, int endY)
{

    char start_color = arr[startX][startY];
    for (int i = startX; i < endX; i++)
        for (int j = startY; j < endY; j++)
        {
            int isSameColor = start_color == arr[i][j];

            if (!isSameColor)
            {
                ans.push_back('(');
                divConq(startX, startY, (startX + endX) / 2, (startY + endY) / 2); // 4사분면
                divConq(startX, (startY + endY) / 2, (startX + endX) / 2, endY);   // 1사분면
                divConq((startX + endX) / 2, startY, endX, (startY + endY) / 2);   // 3사분면
                divConq((startX + endX) / 2, (startY + endY) / 2, endX, endY);     // 2사분면
                ans.push_back(')');
                return;
            }
        }

    ans.push_back(start_color);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    divConq(0, 0, N, N);

    for (auto u : ans)
        cout << u;
}

/*
    (
        (110
            (0101)
        )
        (0010)
        1
        (0001)
    )
*/