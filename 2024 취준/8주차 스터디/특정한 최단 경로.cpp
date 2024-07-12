#include <bits/stdc++.h>
#define MAX 801
#define INF 9876543210LL // long long 사용
using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[MAX];
int N, E, V1, V2;

long long dijkstra(int start, int end)
{
    vector<long long> distance(N + 1, INF);
    distance[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (distance[curNode] < curCost)
            continue;

        for (auto u : adj[curNode])
        {
            int neighbor = u.first;
            int neighborCost = u.second;
            long long neighborDistance = curCost + neighborCost;

            if (neighborDistance < distance[neighbor])
            {
                distance[neighbor] = neighborDistance;
                pq.push({neighborDistance, neighbor});
            }
        }
    }

    return distance[end];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int cur, next, distance;
        cin >> cur >> next >> distance;
        adj[cur].push_back({next, distance});
        adj[next].push_back({cur, distance});
    }

    cin >> V1 >> V2;

    // 1 -> V1 -> V2 -> N 경로
    long long start_v1 = dijkstra(1, V1);
    long long v1_v2 = dijkstra(V1, V2);
    long long v2_N = dijkstra(V2, N);
    long long path1 = (start_v1 == INF || v1_v2 == INF || v2_N == INF) ? INF : start_v1 + v1_v2 + v2_N;

    // 1 -> V2 -> V1 -> N 경로
    long long start_v2 = dijkstra(1, V2);
    long long v2_v1 = dijkstra(V2, V1);
    long long v1_N = dijkstra(V1, N);
    long long path2 = (start_v2 == INF || v2_v1 == INF || v1_N == INF) ? INF : start_v2 + v2_v1 + v1_N;

    long long result = min(path1, path2);
    if (result >= INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << result << "\n";
    }

    return 0;
}
