#include <bits/stdc++.h>
#define MAX 1001
#define endl '\n'

using namespace std;
vector<int> adj[MAX];
bool visited[MAX];

int N, M, V;

void DFS(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    cout << node << ' ';

    for (auto next_node : adj[node])
    {
        DFS(next_node);
    }
}

void BFS(int init_node)
{
    visited[init_node] = true;
    queue<int> q;
    q.push(init_node);

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();

        cout << current_node << ' ';

        for (int next_node : adj[current_node])
        {
            if (visited[next_node])
                continue;

            visited[next_node] = true;
            q.push(next_node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;

    int first_node, second_node;

    for (int i = 0; i < M; i++)
    {
        cin >> first_node >> second_node;
        adj[first_node].push_back(second_node);
        adj[second_node].push_back(first_node);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    DFS(V);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    BFS(V);
}

/*
    DFS 와 BFS
    Tip 1번: 웬만하면 인접리스트로 처리하자. 인접행렬, 간선리스트로 처리하는 것보다 훨씬 많은 경우의 수를 다룰 수 있다.
    Tip 2번 : 나머지는 평범한 DFS / BFS 처리
    Tip 3번 : 헷갈리지 않게 변수명 처리
*/