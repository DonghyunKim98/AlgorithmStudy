#include <bits/stdc++.h>
//1167�� ����
using namespace std;
const int MAX = 100000 + 1;
int N;
//{nextNode, weight}
vector <pair<int, int>> tree[MAX];
int Distance[MAX];
int MaxNode;

void DFS(int currentNode, int parentNode) {
	for (int i = 0; i < tree[currentNode].size(); i++) {
		int nextNode = tree[currentNode][i].first;
		int nextWeight = tree[currentNode][i].second;
		if (nextNode == parentNode) continue;
		Distance[nextNode] = Distance[currentNode] + nextWeight;
		if (Distance[MaxNode] < Distance[nextNode]) MaxNode = nextNode;
		DFS(nextNode, currentNode);
	}
}


void TreeDiameter() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int currentNode;
		cin >> currentNode;
		while (true) {
			int nextNode, weight;
			cin >> nextNode;
			if (nextNode == -1)break;
			cin >> weight;
			tree[currentNode].push_back(make_pair(nextNode, weight));
		}
	}
	//������ ��忡�� DFS����.
	Distance[1] = 0,MaxNode = 0;
	DFS(1, 0);

	//�Ÿ� �ʱ�ȭ �� ���� �� ��忡�� �ٽ� ����
	fill_n(Distance, N + 1, 0);
	Distance[MaxNode] = 0;
	DFS(MaxNode, 0);

	//MaxNode�� Distance ���
	cout << Distance[MaxNode];
}

/*
	�˰��� ����Ʈ
	1) Tree���� DFS�� Ž���ϸ鼭 ���� �Ÿ��� �� �ּҰŸ��� ����. (����Ŭ�� �������� �ʰ� ��忡�� �ٸ� ���� ���� ���� ����)
	2) Tree�� ������ ���ϴ� �˰����� 2���� �ִ� (DP, Greedy)
	�� �� �̷��� weight�� �ο��� ���� Greedy���� Ǯ��� �Ѵ�
	https://www.weeklyps.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84 �� ���� �� ���� ����
	-> �߿��� ���� �˰��� ��ü! (�ܿ��)
		1. ������ ��� v1�� ���� ���� �� v2�� ����
		2. v2�� ���� ���� �� v3�� ����
		3. v2�� v3���� �Ÿ��� �� tree�� ����
*/