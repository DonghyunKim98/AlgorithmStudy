#include <bits/stdc++.h>
//4386번 문제
using namespace std;
const int MAX = 100 + 1;
//{distance {point1, point2}}
vector<pair<double, pair<int, int>>> adj;
vector<pair<double, double>> point(MAX);
int parent[MAX];

bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) {
	return a.first < b.first;
}

int find(int idx) {
	if (parent[idx] == idx) return idx;
	else return parent[idx] = find(parent[idx]);
}

void solution() {
	//소수점 2째자리 까지 출력하기때문에 ios를 쓰지 않음.
	int N;
	cin >> N;
	//처음에 모든 부모는 자기 자신.
	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		double xpos, ypos;
		cin >> xpos >> ypos;
		point[i] = make_pair(xpos, ypos);
	}

	//모든 점을 잇는 그래프 만들기.
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
			adj.push_back({ d,{i,j} });
		}
	}
	//크루스칼 알고리즘을 위한 sorting
	sort(adj.begin(), adj.end(), cmp);
	double answer=0;
	for (int i = 0; i < adj.size(); i++) {
		int point1 = find(adj[i].second.first);
		int point2 = find(adj[i].second.second);
		//부모가 같지 않다면 => 연결되어 있지 않다면
		if (point1 != point2) {
			//point2의 부모를 point1으로
			parent[point2] = point1;
			//거리를 answer에 더해줌
			answer += adj[i].first;
		}
	}

	printf("%.2lf", answer);
}
