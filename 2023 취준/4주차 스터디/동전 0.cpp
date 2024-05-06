#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 동전 액수가 많은걸 최대한 많이 쓰게 (탐욕스럽게)
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;

        ans += K / arr[i];
        K %= arr[i];
    }

    cout << ans;
}

/*
    '탐욕스럽게' = '최대한 많이' 로 해석하는 문제
    실수한 점
    1. K==0 일때 break 를 안함
    2. 배열의 위에서부터 내려오는 구조다 보니깐 i=0 일때까지, 즉 등호를 넣어야 했음
*/