#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M;
vector<ll> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (ll i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end());

    ll begin = 1, end = vc[vc.size() - 1];

    while (begin <= end)
    {
        ll mid = (begin + end) / 2;
        ll cnt = 0;
        for (ll i = 0; i < N; i++)
        {
            if (vc[i] < mid)
                continue;
            cnt += vc[i] - mid;
        }

        // 너무 낮게 자름
        if (cnt >= M)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}