#include <bits/stdc++.h>
//10021�� ����
using namespace std;
const int MAX = 2000 + 1;
typedef pair<int, int> pii;
vector<pair<int,pii>> Distance;
vector<pii> point;
int parent[MAX];
int N, C;

int find(int idx) {
	if (parent[idx] == idx) return idx;
	else return parent[idx] = find(parent[idx]);
}

bool cmp(const pair<double, pii>& a, const pair<double, pii>& b) {
	return a.first < b.first;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> C;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		int xpos, ypos;
		cin >> xpos >> ypos;
		point.push_back({ xpos,ypos });
	}
	for (int i = 0; i < point.size(); i++) {
		for (int j = i + 1; j < point.size(); j++) {
			int xD = abs(point[i].first - point[j].first) * abs(point[i].first - point[j].first);
			int yD = abs(point[i].second - point[j].second) * abs(point[i].second - point[j].second);
			int temp = xD+yD;
			Distance.push_back({ temp, {i,j}});
		}
	}

	sort(Distance.begin(), Distance.end(), cmp);
	int sum = 0, cnt=0;
	for (int i = 0; i < Distance.size(); i++) {
		int point1 = find(Distance[i].second.first);
		int point2 = find(Distance[i].second.second);

		if (point1 != point2&&Distance[i].first>=C) {
			parent[point2] = point1;
			sum += Distance[i].first;
			cnt++;
		}
	}

	if (cnt==N-1) cout << sum; 
	else cout << -1;
}

/*
	Minimum Spanning Tree����
	Why?) ��� �������� ���Ḹ �Ǿ� ������ ��. ���Ḹ �ȴٸ�, Ʈ���� ���� ȿ������(������ N-1���� ���� �Ǵϱ�)
		  �׷��� �Ǹ� Minimum Spanning Tree ������ �ٲ�
*/