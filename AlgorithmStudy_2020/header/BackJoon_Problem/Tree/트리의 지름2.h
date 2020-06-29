#include <bits/stdc++.h>
//1967�� ����
using namespace std;
const int MAX = 10000 + 1;
int N;
vector <pair<int,int>> tree[MAX];
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
	for (int i = 1; i < N; i++) {
		int firstNode, secondNode, weight;
		cin >> firstNode >> secondNode >> weight;
		tree[firstNode].push_back(make_pair(secondNode, weight));
		tree[secondNode].push_back(make_pair(firstNode, weight));
	}

	//������ ��忡�� DFS����.
	Distance[1] = 0, MaxNode = 0;
	DFS(1, 0);

	//�Ÿ� �ʱ�ȭ �� ���� �� ��忡�� �ٽ� ����
	fill_n(Distance, N + 1, 0);
	Distance[MaxNode] = 0;
	DFS(MaxNode, 0);

	//MaxNode�� Distance ���
	cout << Distance[MaxNode];
}