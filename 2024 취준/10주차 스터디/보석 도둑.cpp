#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pii> jewel;
    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;

        jewel.push_back({M, V});
    }

    vector<int> bag;
    for (int i = 0; i < K; i++)
    {
        int C;
        cin >> C;

        bag.push_back(C);
    }

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    long long ans = 0;
    priority_queue<int> pq;
    int jewel_index = 0;

    for (int i = 0; i < K; i++)
    {
        while (jewel_index < N && jewel[jewel_index].first <= bag[i])
        {
            pq.push(jewel[jewel_index].second);
            jewel_index++;
        }

        if (pq.empty())
            continue;

        ans += pq.top(), pq.pop();
    }

    cout << ans;
}

/*
    # 아이디어
    1. 크기가 큰 가방에 들어갈 수 있는 보석은 크기가 작은 가방에도 들어갈 수 있지만 그 역은 성립하지 않는다
    => 크기가 작은 가방부터 최선으로 넣으면 전체가 최선이 됨이 보장된다.

    2. 현재 가방에는 들어갈 수 있는 보석중 최대한 값비싼 보석을 넣는다.
 */