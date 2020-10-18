#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
#define MAX 1001
vector<pii> graph[MAX];
int company[MAX], cost[MAX];
bool visit[MAX];

int dijkstra(int s, int e) {
    priority_queue<pii> pq;
    memset(cost, 0x3f, sizeof(cost));
    cost[s] = 0;
    pq.push(pii(0, s));

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (visit[cur])continue;
        visit[cur] = true;

        for (auto u : graph[cur]) {
            int nxt = u.first;
            int W = u.second;
            if (cost[nxt] > cost[cur] + W) {
                cost[nxt] = cost[cur] + W;
                pq.push(pii(-cost[nxt], nxt));
            }
        }
    }

    return cost[e];
}

#define MAXD 1000000

void solution() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> company[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (i == j || !x)continue;
            if (company[i] == company[j])
                graph[i].emplace_back(j, x);
            else
                graph[i].emplace_back(j, x + MAXD);
        }
    }

    int answer = dijkstra(0, m);
    cout << answer / MAXD << " " << answer % MAXD;

}

/*
    진짜 대단하다고 느껴질수 밖에 없는 코드.
    원래 코드가 틀린 이유는 '환승을 덜하기 -> 더 적은 비용으로 운행하기' 라는 2가지 조건을 만족시키지 못하는 반례가 있었을 것이다.
*/