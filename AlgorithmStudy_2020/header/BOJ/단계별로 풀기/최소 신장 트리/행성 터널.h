#include <bits/stdc++.h>
//2887�� ����
//https://dev-jk.tistory.com/29 ����
using namespace std;
typedef long long ll;
const int MAX = 100000;
vector<pair<ll, pair<ll, pair<ll, ll>>>> node;
vector<pair<ll, pair<int, int>>> adj;
int parent[MAX];

int find(int idx) {
	if (parent[idx] == idx) return idx;
	else return parent[idx] = find(parent[idx]);
}

bool cmpx(pair<ll, pair<ll, pair<ll, ll>>> a, pair<ll, pair<ll, pair<ll, ll>>> b) {
	return a.second.first < b.second.first;
}

bool cmpy(pair<ll, pair<ll, pair<ll, ll>>> a, pair<ll, pair<ll, pair<ll, ll>>> b) {
	return a.second.second.first < b.second.second.first;
}

bool cmpz(pair<ll, pair<ll, pair<ll, ll>>> a, pair<ll, pair<ll, pair<ll, ll>>> b) {
	return a.second.second.second < b.second.second.second;
}

bool cmpAdj(pair<ll, pair<int, int>> a, pair<ll, pair<int, int>> b) {
	return a.first < b.first;
}
void solution() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		long long xpos, ypos, zpos;
		cin >> xpos >> ypos >> zpos;
		node.push_back(make_pair(i,make_pair(xpos, make_pair(ypos, zpos))));
	}

	//x���� sort -> ����ֱ�
	sort(node.begin(), node.end(), cmpx);
	for (int i = 0; i < N - 1; i++) {
		long long xD = abs(node[i].second.first - node[i + 1].second.first);
		adj.push_back(make_pair(xD, make_pair(node[i].first, node[i+1].first)));
	}
	//y���� sort -> ����ֱ�
	sort(node.begin(), node.end(), cmpy);
	for (int i = 0; i < N - 1; i++) {
		long long yD = abs(node[i].second.second.first - node[i + 1].second.second.first);
		adj.push_back(make_pair(yD, make_pair(node[i].first, node[i+1].first)));
	}
	//z���� sort -> ����ֱ�
	sort(node.begin(), node.end(), cmpz);
	for (int i = 0; i < N - 1; i++) {
		long long zD = abs(node[i].second.second.second - node[i + 1].second.second.second);
		adj.push_back(make_pair(zD, make_pair(node[i].first, node[i + 1].first)));
	}

	sort(adj.begin(), adj.end(), cmpAdj);
	ll answer = 0;
	for (int i = 0; i < adj.size(); i++) {
		int point1 = find(adj[i].second.first);
		int point2 = find(adj[i].second.second);

		if (point1 != point2) {
			parent[point1] = point2;
			answer += adj[i].first;
		}
	}
	cout << answer << '\n';
}

/*
	������ 100000�� �̹Ƿ� �׳� adj�� �� �����ϰ� ������ �翬�� �޸� �ʰ�.

	�˰��� ����Ʈ
	=> x���� y���� z���� sort
	=> x�� �������� ��ǥ������ sort�� ������ i��° idx�� ���� ����� ��ǥ��? -> (idx-1 or idx+1)
	=> �׷��Ƿ� 0��°���� �������� (i,i+1)���� ������ adj�� �־��ָ� ��.
	=> ������ �װ� i��°���� i+1�� ���� �ּ���.

	�Ǽ��� ��
	-> �̰� �����ϰ� adj�� �ֱ� ������ �ݺ��� �󿡼� i��° node�� ������ i��° ��尡 �ƴ�
	-> �ڷῡ ���� ��ø� �ؾ���
	-> 4���� �Ѿ�� 2/2 �� �ɰ����°��� �ƴϴ� ����, struct ������ �� ���ϱ� �ҵ�.
*/