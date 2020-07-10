#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000 + 1;
vector<int> adj[MAX];
//cnt�� �� node�� �������� ����� �߰� ������Ʈ�� ����
int cnt[MAX], dfsn[MAX], dcnt;

int dfs(int current, int parent) {
	int temp, ret = dfsn[current] = dcnt++;
	for (int next : adj[current]) {
		//���� ��尡 parent�� �ƴҶ�
		if (next != parent) {
			//���� ��带 �湮���� ������ �湮
			if (dfsn[next] == -1)
				temp = dfs(next, current);
			//���� ��带 �湮������
			else {
				temp = dfsn[next];
				if (temp > dfsn[current]) continue;
			}
			if (temp >= dfsn[current]) ++cnt[current];
			ret = min(temp, ret);
		}
	}
	//ù�� ���� ó��
	if (parent == -1) cnt[current] = max(0, cnt[current] - 1);
	return ret;
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	//�� node�� ������ ���� �ľ�
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	fill_n(dfsn, MAX, -1);
	dfs(1, -1);


	//���� �׷��� �󿡼� ����Ŭ�� ��������(tree) edge�� ������ node-1
	//�ɼ� �ִ� ����� ���� �ľ�.
	for (int i = 1; i <= n; i++) {
		if (edges.size() - adj[i].size() + cnt[i] < n - 1) answer += i;
	}
	return answer;
}

/*
	(��ü ������ ��) - (i�� ������ ����� ������ ��) + (�߰��� ��������� ������Ʈ�� ��) < (��ü ������ ��) - 1
	�� ���� ��Ű�� ��尡 �츮�� ���ϴ� ���.
*/