#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int N, M, K;
int arrA[MAX][MAX], arrB[MAX][MAX], ans_arr[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arrA[i][j];

    cin >> M >> K;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> arrB[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < M; k++)
                ans_arr[i][j] += (arrA[i][k] * arrB[k][j]);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
            cout << ans_arr[i][j] << ' ';
        cout << '\n';
    }
}