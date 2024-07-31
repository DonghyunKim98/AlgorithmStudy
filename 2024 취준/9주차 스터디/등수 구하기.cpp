#include <bits/stdc++.h>

using namespace std;

int N, new_score, P;
int arr[51];

int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
    cin >> N >> new_score >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    if (N == 0)
    {
        cout << 1;
        return 0;
    }

    int rank = 1;

    for (int i = 0; i <= N; i++)
    {
        if (i == N)
        {
            cout << -1;
            return 0;
        }

        if (arr[i] > new_score)
        {
            rank++;
        }
        else if (arr[i] < new_score)
        {
            break;
        }
        // 같은 경우는 넘어감
    }

    cout << rank;
}