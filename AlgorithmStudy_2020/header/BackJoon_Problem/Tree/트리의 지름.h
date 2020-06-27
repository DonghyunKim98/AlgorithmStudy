#include <bits/stdc++.h>
//1167번 문제
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
	//임의의 노드에서 DFS시작.
	Distance[1] = 0,MaxNode = 0;
	DFS(1, 0);

	//거리 초기화 후 가장 먼 노드에서 다시 시작
	fill_n(Distance, N + 1, 0);
	Distance[MaxNode] = 0;
	DFS(MaxNode, 0);

	//MaxNode의 Distance 출력
	cout << Distance[MaxNode];
}

/*
	알고리즘 포인트
	1) Tree에선 DFS로 탐색하면서 얻은 거리가 곧 최소거리를 보장. (사이클이 존재하지 않고 노드에서 다른 노드로 가는 길이 유일)
	2) Tree의 지름을 구하는 알고리즘은 2개가 있다 (DP, Greedy)
	그 중 이렇게 weight가 부여된 것은 Greedy으로 풀어야 한다
	https://www.weeklyps.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84 를 통해 왜 인지 참고
	-> 중요한 것은 알고리즘 자체! (외울것)
		1. 임의의 노드 v1에 대해 제일 먼 v2를 구함
		2. v2에 대해 제일 먼 v3를 잡음
		3. v2와 v3간의 거리가 곧 tree의 지름
*/