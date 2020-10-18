#include <bits/stdc++.h>
//11725�� ����
using namespace std;
const int MAX = 100000 + 1;

int N;
vector <int> tree[MAX];
vector <int> answer(MAX);
void DFS(int currentNode, int parentNode){
	for (auto u : tree[currentNode]) {
		if (u != parentNode) {
			//u�� parentNode�� currentNode�ϱ�.
			answer[u] = currentNode;
			DFS(u, currentNode);
		}
	}
}

void TreeParent() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int firstNode, secondNode; 
		cin >> firstNode >> secondNode;
		tree[firstNode].push_back(secondNode);
		tree[secondNode].push_back(firstNode);
	}
	//DFS
	DFS(1,0);
	
	for (int i = 2; i <= N; i++)
		cout << answer[i] << '\n';
}

/*
	�˰��� ����Ʈ
	1) DFS�� �����Ҷ� tree�� ����Ŭ�� �ݵ�� �����Ƿ� visited �迭������ �Դ� �迭���� üũ X
	=> �� ��带 �ö��� ������ ����ϰ� ���ϸ� ��
*/