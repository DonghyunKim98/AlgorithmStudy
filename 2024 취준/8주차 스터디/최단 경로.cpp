#include <bits/stdc++.h>
#define MAX 20001
#define INF 2147483647

using namespace std;
typedef pair<int, int> pii;

int V, E, K;
vector<pii> adj[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> V >> E;
    cin >> K;

    // 정점 번호 0번이 아닌 1번부터 시작한다는 것을 항상 명심
    for (int i = 1; i <= E; i++)
    {
        int source, destination, cost;
        cin >> source >> destination >> cost;
        adj[source].push_back({destination, cost});
    }

    vector<int> distance(V + 1, INF);
    distance[K] = 0; // 시작은 0으로

    priority_queue<pii> pq;
    pq.push({0, K});

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        int cost = -cur.first;
        int curVertex = cur.second;

        // 이미 있는 값과 비교해서 최소가 아니면 버림
        if (distance[curVertex] < cost)
            continue;

        for (auto u : adj[curVertex])
        {
            int neighbor = u.first;
            int neighborDistance = cost + u.second;

            // 최단 경로 발견
            if (distance[neighbor] > neighborDistance)
            {
                distance[neighbor] = neighborDistance;
                // 부호 바꾸는게 키포인트! -> 거리가 작은 정점부터 꺼내야 하므로
                pq.push({-neighborDistance, neighbor});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (distance[i] == INF)
            cout << "INF" << endl;
        else
            cout << distance[i] << endl;
    }
}