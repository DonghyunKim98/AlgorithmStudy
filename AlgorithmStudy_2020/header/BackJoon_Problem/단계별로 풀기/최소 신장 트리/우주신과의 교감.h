#include <bits/stdc++.h>
//1774번 문제
using namespace std;
const int MAX = 1000;
int N, M;
pair<double, double> point[MAX];
vector<pair<double, pair<int, int>>> adj;
int parent[MAX];

bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) {
	return a.first < b.first;
}
int find(int idx) {
	if (parent[idx] == idx) return idx;
	else return parent[idx] = find(parent[idx]);
}

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		double xpos, ypos;
		cin >> xpos >> ypos;
		point[i] = make_pair(xpos, ypos);
	}

	//tree parent initialization
	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int point1, point2;
		cin >> point1 >> point2;
		//point1과 point2 연결
		int parent1 = find(point1-1), parent2 = find(point2-1);
		if (parent1 != parent2) 
			parent[parent1] = parent2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
			adj.push_back({ d,{i,j} });
		}
	}
	sort(adj.begin(), adj.end(), cmp);
	double answer = 0;
	for (int i = 0; i < adj.size(); i++) {
		int point1 = find(adj[i].second.first);
		int point2 = find(adj[i].second.second);
		if (point1 != point2) {
			parent[point2] = point1;
			answer += adj[i].first;
		}
	}

	printf("%.2lf", answer);
}