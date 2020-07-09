#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    //승리한 경우 true
    //u[0]가 u[1]을 이겼다.
    for (auto u : results) 
        adj[u[0]][u[1]] = true;
    //플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //i가 k를 이겼고 k가 j를 이겼으면 i가 j를 이긴것.
                if (adj[i][k] && adj[k][j]) adj[i][j] = true;
            }
        }
    }

    //내가 이긴 사람 + 내가 진 사람
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        //i번 노드에게 이긴 사람 adj[i][j]
        //i번 노드에게 진 사람   adj[j][i]
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] || adj[j][i]) cnt++;
        }
        if (cnt == n - 1)answer++;
    }

    return answer;
}

/*
    일단 이게 그래프문제인지 떠올리는 것 자체부터가 굉장한 것.
    "사건"들의 관계가 단 2개로 얽혀있다면 (어디서 어디로 간다, 누가 누구와 시합을 했다 등) 그래프 문제인지 의심해봐야 하는 것 같다.

    알고리즘 포인트
    => 플로이드-워셜 알고리즘
    => 대각선을 기준으로 내가 이긴 사람, 내가 진 사람의 count가 되니깐.
    => 가능한 이유는 선수가 고작 100명.

    * 나간 노드 + 들어온 노드 == n-1 까진 밝혀냈는데 이를 구현하는 방법을 떠올리지 못했다.
      구현이 어려운 문제, 아예 떠올리지 조차 못하는 문제가 있는데 이 문제는 구현이 어려운 문제이다.

    * size_t에 대한 발견. 
*/