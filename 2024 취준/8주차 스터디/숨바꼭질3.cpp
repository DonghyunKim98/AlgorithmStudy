#include <bits/stdc++.h>
#define MAX 100001
#define INF 10000000

using namespace std;
typedef pair<int, int> pii;

int N, K;
vector<pii> adj[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    // 범위가 1 ~ 100,000 이므로 해당 범위에 맞춰 adj 벡터를 설정
    for (int i = 0; i < MAX; i++)
    {
        if (i - 1 >= 0)
            adj[i].push_back({i - 1, 1});
        if (i + 1 < MAX)
            adj[i].push_back({i + 1, 1});
        if (i * 2 < MAX)
            adj[i].push_back({i * 2, 0});
    }

    vector<int> distance(MAX, INF);
    distance[N] = 0;

    // 최소 힙 사용
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, N});

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        int cost = cur.first;
        int curVertex = cur.second;

        if (distance[curVertex] < cost)
            continue;

        for (auto u : adj[curVertex])
        {
            int neighbor = u.first;
            int neighborDistance = cost + u.second;

            if (distance[neighbor] > neighborDistance)
            {
                distance[neighbor] = neighborDistance;
                pq.push({neighborDistance, neighbor});
            }
        }
    }

    cout << distance[K] << endl;

    return 0;
}
