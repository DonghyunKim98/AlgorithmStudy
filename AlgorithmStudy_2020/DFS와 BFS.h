#include <bits/stdc++.h>

//1260�� ���� ->Ǯ����!
//https://blog.naver.com/hwasub1115/221183031039 ����

using namespace std;
//��������Ʈ ������ �׷���
vector<int> adj[1001];
//DFS�� ���� �غ�
bool visited[1001] = { false, };
//BFS�� ���� �غ�
queue <int> q;

int N, M, X;

void DFS(int s) {
	if (visited[s]) return;
	visited[s] = true;
	cout << s << ' ';
	for (int y : adj[s]) {
		DFS(y);
	}
}

void BFS(int x) {	
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		//��� s ó��
		cout << s << ' ';
		for (int y: adj[s]) {
			if (visited[y]) continue;
			visited[y] = true;
			q.push(y);
		}	
	}
}

void Init() {
	for (int i = 1; i <= 1000; i++) visited[i] = false;
}

void DFS_BFS() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//X�� ���۳��
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}

	//���� ��ȣ���� �湮�ؾ� �ϹǷ� ����
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(),adj[i].end());
	}

	DFS(X);
	cout << "\n";
	Init();
	BFS(X);
}

/*
	������ ��
	1) index �ѹ����� ����. �迭�� 1001���� �����ؾ��Ѵ�.
	2) ���� ������ "�湮�� �� �ִ� ������ ���� ���� ��� ���� ��ȣ�� ���� ���� ���� �湮" �� �ذ��ؾ���
	-> sorting ���� �ذ�.
	3) distance �� ���� �ذ� �������� ���� ���� visited�� ���� 2���� ������ ����X
	-> �޸𸮸� �Ʋ�����.
*/