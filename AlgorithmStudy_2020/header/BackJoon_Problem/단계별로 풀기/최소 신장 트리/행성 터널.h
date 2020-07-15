#include <bits/stdc++.h>
//2887번 문제
//https://dev-jk.tistory.com/29 참고
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

	//x기준 sort -> 집어넣기
	sort(node.begin(), node.end(), cmpx);
	for (int i = 0; i < N - 1; i++) {
		long long xD = abs(node[i].second.first - node[i + 1].second.first);
		adj.push_back(make_pair(xD, make_pair(node[i].first, node[i+1].first)));
	}
	//y기준 sort -> 집어넣기
	sort(node.begin(), node.end(), cmpy);
	for (int i = 0; i < N - 1; i++) {
		long long yD = abs(node[i].second.second.first - node[i + 1].second.second.first);
		adj.push_back(make_pair(yD, make_pair(node[i].first, node[i+1].first)));
	}
	//z기준 sort -> 집어넣기
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
	정점이 100000개 이므로 그냥 adj에 다 무식하게 넣으면 당연히 메모리 초과.

	알고리즘 포인트
	=> x따로 y따로 z따로 sort
	=> x를 기준으로 좌표순으로 sort를 했을때 i번째 idx와 제일 가까운 좌표는? -> (idx-1 or idx+1)
	=> 그러므로 0번째부터 차곡차곡 (i,i+1)간의 간격을 adj에 넣어주면 됨.
	=> 어차피 그게 i번째에서 i+1로 가는 최소임.

	실수한 것
	-> 이건 정렬하고 adj에 넣기 때문에 반복문 상에서 i번째 node가 실제로 i번째 노드가 아님
	-> 자료에 따로 명시를 해야함
	-> 4개를 넘어가고 2/2 로 쪼개지는것이 아니다 보니, struct 구조가 더 편하긴 할듯.
*/