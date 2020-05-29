#include <bits/stdc++.h>
//2606�� ���� -> (�¾���)
using namespace std;

//������Ʈ�� �ִ� ��� ������ ���ϴ� ����

vector<int> adj[100];
bool visited[100] = { false ,};
int cnt=0;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	cnt++;
	for (auto u : adj[s]) {
		dfs(u);
	}
}

void Virus() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	dfs(1);
	cout << cnt-1<<endl;
}

/*
	�����ؾ��� ��
	1) count ������ std ���̺귯������ �ִ� �׷��� ���������� �����ϸ�,
	��ȣ�ϴٰ� �Ѵ�. �ٸ� ������ �ٲپ�����.
	2) ���� ó�� § ��� �ϸ� 1�� ��ǻ�ͱ��� ī������ �ϴ°��̱� ������ �������� �ϳ��� ���ش�.
*/