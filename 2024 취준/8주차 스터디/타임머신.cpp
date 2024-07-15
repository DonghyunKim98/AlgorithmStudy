#include <bits/stdc++.h>
#define MAX 501
#define INF 987654321LL
#define endl '\n'

using namespace std;
typedef long long ll;

int N, M;
vector<tuple<int, int, ll>> edges;
ll distances[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        edges.push_back({start, end, cost});
    }

    fill_n(distances, MAX, INF);
    distances[1] = 0; // 1번 도시에서 출발
    bool is_negative_cycle_exist = false;

    // 원래는 N-1 번 돌려야함 , N 번째에는 더 줄어드는지를 체크하는 것 (음수 사이클 존재 여부)
    for (int i = 1; i <= N; i++)
    {
        for (auto e : edges)
        {
            int curVertex, neighbor;
            ll cost;
            tie(curVertex, neighbor, cost) = e;

            // 아직 한번도 방문 / 계산되지 않음
            if (distances[curVertex] == INF)
                continue;

            if (i == N && distances[neighbor] > distances[curVertex] + cost)
                is_negative_cycle_exist = true;

            distances[neighbor] = min(distances[neighbor], distances[curVertex] + cost);
        }
    }

    if (is_negative_cycle_exist)
        cout << "-1" << endl;
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (distances[i] == INF)
                cout << "-1" << endl;
            else
                cout << distances[i] << endl;
        }
    }
}