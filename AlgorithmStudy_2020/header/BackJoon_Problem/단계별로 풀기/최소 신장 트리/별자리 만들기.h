#include <bits/stdc++.h>
//4386�� ����
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
	//�Ҽ��� 2°�ڸ� ���� ����ϱ⶧���� ios�� ���� ����.
	int N;
	cin >> N;
	//ó���� ��� �θ�� �ڱ� �ڽ�.
	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		double xpos, ypos;
		cin >> xpos >> ypos;
		point[i] = make_pair(xpos, ypos);
	}

	//��� ���� �մ� �׷��� �����.
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
			adj.push_back({ d,{i,j} });
		}
	}
	//ũ�罺Į �˰����� ���� sorting
	sort(adj.begin(), adj.end(), cmp);
	double answer=0;
	for (int i = 0; i < adj.size(); i++) {
		int point1 = find(adj[i].second.first);
		int point2 = find(adj[i].second.second);
		//�θ� ���� �ʴٸ� => ����Ǿ� ���� �ʴٸ�
		if (point1 != point2) {
			//point2�� �θ� point1����
			parent[point2] = point1;
			//�Ÿ��� answer�� ������
			answer += adj[i].first;
		}
	}

	printf("%.2lf", answer);
}
