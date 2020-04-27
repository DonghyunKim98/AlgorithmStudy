#include <bits/stdc++.h>

using namespace std;

void AdjacencyList();
void AdjacencyMatrix();
void EdgeList();

typedef vector<int> vi;
typedef vector<pair<int, int>> pi;

#define first get<0>
#define second get<1>
#define third get<2>

void GraphRepresentation() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << "그래프의 표현 방법중 어떤 것을 선택할지 고르세요! \n";

	cout << "1) 인접 리스트(Adjacency list)로 표현하기 \n";
	cout << "2) 인접 행렬(Adjacency Matrix)로 표현하기 \n";
	cout << "3) 간선 리스트(Edge List)로 표현하기\n";
	cout << ":";
	try {
		string temp;
		cin >> temp;
		if (temp != "1" && temp != "2" && temp != "3") throw temp;

		else if (temp == "1") AdjacencyList();
		else if (temp == "2") AdjacencyMatrix();
		else EdgeList();
	}
	catch(string s){
		cout << "잘못된 입력" << s << "를 입력하셨습니다.\n";
	}

	cout << "그래프의 표현 끝!" << endl;
}

void AdjacencyList() {
	cout << "몇개의 노드가 있나요?" << endl;
	int N;
	cin >> N;
	cout << "몇개의 간선이 있나요?" << endl;
	int M;
	cin >> M;
	string temp;
	while (true) {
		cout << "가중치가 있는 그래프인가요?? (Y/N)";
		cin >> temp;
		if (temp != "Y" && temp != "N") {
			cout << "잘못된 값을 입력했습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else break;
	}
	//가중 그래프 상황
	if (temp == "Y") {
		pi* adj = new pi[N];
		cout << "<노드의 위치 / 다음 노드의 위치 / 가중치>  순으로 입력하세요." << endl;
		for (int i = 0; i < N + M; i++) {
			int a, b, w;
			cin >> a, b, w;
			adj[a].push_back({b,w});
		}
		cout << "주어진 그래프의 모든 위치를 출력합니다." << endl;

		for (int i = 0; i < N; i++) {
			for (auto e : adj[i]) cout << "(" << i << "," << first(e) << "," << second(e) << ")"<<endl;
		}
	}
	//가중 그래프가 아닌 상황
	else {
		vi* adj = new vi[N];
		cout << "<노드의 위치 / 다음 노드의 위치> 순으로 입력하세요." << endl;
		for (int i = 0; i < N + M; i++) {
			int a, b;
			cin >> a, b;
			adj[a].push_back(b);
		}
		cout << "주어진 그래프의 모든 위치를 출력합니다." << endl;
		for (int i = 0; i < N; i++) {
			for (auto e : adj[i]) cout << "(" << i << "," << e << ")";
		}
	}
}

void AdjacencyMatrix() {

}

void EdgeList() {

}