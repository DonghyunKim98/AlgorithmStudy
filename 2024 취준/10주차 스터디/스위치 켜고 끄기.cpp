#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int gender, position;
        cin >> gender >> position;

        if (gender == 1)
        {
            for (int j = position; j <= N; j += position)
            {
                arr[j] = arr[j] == 1 ? 0 : 1;
            }
        }
        else
        {
            arr[position] = arr[position] == 1 ? 0 : 1;
            for (int j = 1;; j++)
            {
                if (1 <= position - j && position + j <= N && arr[position + j] == arr[position - j])
                {
                    arr[position + j] = arr[position + j] == 1 ? 0 : 1;
                    arr[position - j] = arr[position - j] == 1 ? 0 : 1;
                }
                else
                    break;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0) // 20개의 숫자를 출력했다면 줄바꾸기
            cout << endl;
    }
}