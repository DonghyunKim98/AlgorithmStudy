#include <bits/stdc++.h>

using namespace std;

#define MAX 8
#define endl "\n"

vector<int> adj;
int N, M;
bool visited[MAX];

void dfs(int k)
{
    if (k == M)
    {
        for (auto u : adj)
        {
            cout << u << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        adj.push_back(i);
        dfs(k + 1);
        adj.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    dfs(0);

    return 0;
}

/*
    N 과 M(3)
    중복 순열 문제
    1. visited 만 없애면 됨 (백트래킹이라기 보다는 브루탈포스에 가까움)
*/