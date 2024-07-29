#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001

using namespace std;

int N, dist[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> dist[i];
    }

    long long MIN_PRICE = 1000000001, ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        long long temp;
        cin >> temp;
        MIN_PRICE = min(MIN_PRICE, temp);
        ans += dist[i] * MIN_PRICE;
    }

    cout << ans;
}