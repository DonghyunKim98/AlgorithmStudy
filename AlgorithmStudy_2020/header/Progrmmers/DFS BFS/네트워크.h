#include <bits/stdc++.h>
using namespace std;
const int MAX = 200+1;
bool visited[MAX];
vector<int> vc[MAX];
int answer=0;
//컴포넌트의 개수 출력하는 문제
void DFS(int current_node) {
    if (visited[current_node]) return;
    visited[current_node] = true;
    for (auto u : vc[current_node])
        DFS(u);
}
int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //자기 자신은 제외.
            if (i == j) continue;
            if (computers[i][j] == 1) vc[i].push_back(j);

        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
            answer++;
        }
    }
    return answer;
}