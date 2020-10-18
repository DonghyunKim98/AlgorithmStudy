#include <bits/stdc++.h>
//1197번 문제
using namespace std;
const int MAX = 100000;
vector<vector<int>> vc;
int parent[MAX];

int find(int idx) {
	if (parent[idx] == idx) return idx;
	else return parent[idx]=find(parent[idx]);
}

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int current, next, weight;
		cin >> current >> next >> weight;
		vector<int> temp = { current,next,weight };
		vc.push_back(temp);
	}
	//가중치 기준 오름차순 정렬
	sort(vc.begin(), vc.end(), cmp);

	//부모 처리 -> 맨 처음엔 모든 노드가 곧 부모
	for (int i = 0; i < V; i++) parent[i] = i;
	
	int answer = 0;
	//모든 간선을 검사
	for (int i = 0; i < vc.size(); i++) {
		int current = find(vc[i][0]);
		int next = find(vc[i][1]);
		int cost = vc[i][2];

		//연결되어 있지 않다면
		if (current != next) {
			//current의 부모를 next로 설정
			parent[current] = next;
			//간선의 가중치를 결과에 더해줌
			answer += cost;
		}
	}
	cout << answer;
}