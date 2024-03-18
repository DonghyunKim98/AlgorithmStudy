// N 과 M (1)
#include <bits/stdc++.h>
#define endl "\n"
#define MAX 9

using namespace std;

int N, M;
vector<int> adj;
bool visited[MAX];

// k -> Depth 를 의미하는 변수
void dfs(int k)
{
    // 재귀 DFS 에서 반드시 필요한 것. 탈출문이 필요하다. (끝까지 탐색한 경우)
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
        if (!visited[i])
        {
            // 유망하니깐 탐색
            visited[i] = true;
            adj.push_back(i);
            dfs(k + 1);
            // 탐색이 끝난후에는 Back-Tracking
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

    dfs(0);

    return 0;
}

/*
    기본적인 백트래킹. 코드 꼴에 익숙해져야 한다.
    (1) #define 을 사용하는 부분
    (2) auto 구문
*/