#include <bits/stdc++.h>
//1197�� ����
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
	//����ġ ���� �������� ����
	sort(vc.begin(), vc.end(), cmp);

	//�θ� ó�� -> �� ó���� ��� ��尡 �� �θ�
	for (int i = 0; i < V; i++) parent[i] = i;
	
	int answer = 0;
	//��� ������ �˻�
	for (int i = 0; i < vc.size(); i++) {
		int current = find(vc[i][0]);
		int next = find(vc[i][1]);
		int cost = vc[i][2];

		//����Ǿ� ���� �ʴٸ�
		if (current != next) {
			//current�� �θ� next�� ����
			parent[current] = next;
			//������ ����ġ�� ����� ������
			answer += cost;
		}
	}
	cout << answer;
}