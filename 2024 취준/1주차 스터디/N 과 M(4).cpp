#include <bits/stdc++.h>
#define MAX 9
#define endl "\n"

using namespace std;

int N, M;
vector<int> adj;

void DFS(int k)
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
        if (!adj.empty() && adj.back() > i)
            continue;
        adj.push_back(i);
        DFS(k + 1);
        adj.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    DFS(0);

    return 0;
}

/*
    N 과 M (4)
    - 2번 아이디어 (오름차순) + 3번 아이디어
*/