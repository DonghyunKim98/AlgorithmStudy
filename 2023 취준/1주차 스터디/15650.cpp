// N 과 M (2)
#include <bits/stdc++.h>

#define endl "\n"
#define MAX 9

using namespace std;

int N, M;
vector<int> adj;
bool visited[MAX];

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
        // 핵심 -> 마지막 원소보다 반드시 크게 만들면 됨!!! (오름차순을 구현한 것)
        if (!adj.empty() && adj.back() > i)
            continue;
        if (!visited[i])
        {
            visited[i] = true;
            adj.push_back(i);
            DFS(k + 1);
            visited[i] = false;
            adj.pop_back();
        }
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
    조합 문제
    (1) 순열 + 오름차순을 구현하면 된다. (진짜 조합으로 생각 안해도 된다.)
*/