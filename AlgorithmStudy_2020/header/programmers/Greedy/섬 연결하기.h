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

        //�湮�ߴ��� ���θ� �������� cost�� �� ū���� Ȯ���ϸ� ��.
        if (Distance[current_node] < cost) continue;

        //neighbor �� Ȯ��
        for (auto u : adj[current_node]) {
            int neighbor = u.first;
            int neighbor_cost = cost+ u.second;

            //�ִܿ��� Ȯ��
            if (Distance[neighbor] > neighbor_cost) {
                //�� ������ ����� ���̹Ƿ� answer�� �߰�����
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
    //���ͽ�Ʈ�� �˰���
    return answer;
}

/*
    ���� �ؼ� 
    =>�ּ� ��� , ��� �� ���� ����, �ٸ� ������ �ǳ� �� ����, ������ �ٲ� ���� ����(����� ����&����ġ ����)
    
    ���ͽ�Ʈ�� �˰���(������ �ȳ����ϱ�) �ؼ� �� ������ check.
*/
