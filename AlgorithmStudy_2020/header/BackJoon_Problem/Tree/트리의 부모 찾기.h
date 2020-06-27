#include <bits/stdc++.h>
//11725번 문제
using namespace std;
const int MAX = 100000 + 1;

int N;
vector <int> tree[MAX];
vector <int> answer(MAX);
void DFS(int currentNode, int parentNode){
	for (auto u : tree[currentNode]) {
		if (u != parentNode) {
			//u의 parentNode는 currentNode니깐.
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
	알고리즘 포인트
	1) DFS를 진행할때 tree는 사이클이 반드시 없으므로 visited 배열등으로 왔던 배열인지 체크 X
	=> 이 노드를 올때의 직전의 노드하고만 비교하면 됨
*/