#include <bits/stdc++.h>
using namespace std;
const int MAX = 20000 + 1;
int Distance[MAX];
bool visited[MAX];
vector<int> adj[MAX];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, cnt = 0;
    fill_n(Distance, MAX, INT_MAX);
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    //BFS
    queue<int> q;
    q.push(1);
    Distance[1] = 0, visited[1]=true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto u : adj[current]) {
            if (visited[u]) continue;
            visited[u] = true;
            Distance[u] = Distance[current] + 1;
            cnt = max(Distance[u], cnt);
            q.push(u);
        }
    }

    for (int i = 1; i <= n; i++)
        if (Distance[i] == cnt) answer++;
    return answer;
}