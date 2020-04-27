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

	cout << "�׷����� ǥ�� ����� � ���� �������� ������! \n";

	cout << "1) ���� ����Ʈ(Adjacency list)�� ǥ���ϱ� \n";
	cout << "2) ���� ���(Adjacency Matrix)�� ǥ���ϱ� \n";
	cout << "3) ���� ����Ʈ(Edge List)�� ǥ���ϱ�\n";
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
		cout << "�߸��� �Է�" << s << "�� �Է��ϼ̽��ϴ�.\n";
	}

	cout << "�׷����� ǥ�� ��!" << endl;
}

void AdjacencyList() {
	cout << "��� ��尡 �ֳ���?" << endl;
	int N;
	cin >> N;
	cout << "��� ������ �ֳ���?" << endl;
	int M;
	cin >> M;
	string temp;
	while (true) {
		cout << "����ġ�� �ִ� �׷����ΰ���?? (Y/N)";
		cin >> temp;
		if (temp != "Y" && temp != "N") {
			cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		else break;
	}
	//���� �׷��� ��Ȳ
	if (temp == "Y") {
		pi* adj = new pi[N];
		cout << "<����� ��ġ / ���� ����� ��ġ / ����ġ>  ������ �Է��ϼ���." << endl;
		for (int i = 0; i < N + M; i++) {
			int a, b, w;
			cin >> a, b, w;
			adj[a].push_back({b,w});
		}
		cout << "�־��� �׷����� ��� ��ġ�� ����մϴ�." << endl;

		for (int i = 0; i < N; i++) {
			for (auto e : adj[i]) cout << "(" << i << "," << first(e) << "," << second(e) << ")"<<endl;
		}
	}
	//���� �׷����� �ƴ� ��Ȳ
	else {
		vi* adj = new vi[N];
		cout << "<����� ��ġ / ���� ����� ��ġ> ������ �Է��ϼ���." << endl;
		for (int i = 0; i < N + M; i++) {
			int a, b;
			cin >> a, b;
			adj[a].push_back(b);
		}
		cout << "�־��� �׷����� ��� ��ġ�� ����մϴ�." << endl;
		for (int i = 0; i < N; i++) {
			for (auto e : adj[i]) cout << "(" << i << "," << e << ")";
		}
	}
}

void AdjacencyMatrix() {

}

void EdgeList() {

}