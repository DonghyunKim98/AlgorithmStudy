#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 1;
vector<pair<int, int>> adj[MAX];

int diksjtra(int start,int vertex) {
    vector<int> Distance(vertex,INT_MAX);
    Distance[start] = 0;
    int answer = 0;
    //{-distance,current_node}
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        //방문했는지 여부를 기존보다 cost가 더 큰지로 확인하면 됨.
        if (Distance[current_node] < cost) continue;

        //neighbor 다 확인
        for (auto u : adj[current_node]) {
            int neighbor = u.first;
            int neighbor_cost = cost+ u.second;

            //최단여부 확인
            if (Distance[neighbor] > neighbor_cost) {
                //이 간선을 사용할 것이므로 answer에 추가해줌
                answer += u.second;
                Distance[neighbor] = neighbor_cost;
                pq.push(make_pair(-neighbor_cost, neighbor));
            }
        }
    }
    return answer;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < costs.size(); i++) {
        int start_node = costs[i][0];
        int end_node = costs[i][1];
        int weight = costs[i][2];
        adj[start_node].push_back(make_pair(end_node, weight));
        adj[end_node].push_back(make_pair(start_node, weight));
    }

    answer = diksjtra(0,n);
    //디익스트라 알고리즘
    return answer;
}

/*
    문제 해설 
    =>최소 비용 , 모든 섬 통행 가능, 다리 여러번 건널 수 있음, 순서가 바뀌어도 같은 연결(양방향 간선&가중치 같음)
    
    디익스트라 알고리즘(음수가 안나오니깐) 해서 쓴 간선만 check.
*/
