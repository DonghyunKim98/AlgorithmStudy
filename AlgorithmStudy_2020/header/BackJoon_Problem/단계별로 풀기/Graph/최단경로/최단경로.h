#include <bits/stdc++.h>
//1753�� ����
//���ͽ�Ʈ�� �˰��� �̿�
//https://jaimemin.tistory.com/555 ����
using namespace std;
const int MAX = 20000 + 1;
const int INF = 2147483647;
int V, E, K;
vector<pair<int, int>> adj[MAX];

vector<int> dijkstra(int start, int vertex){
	vector<int> Distance(vertex,INF); //start�� �������� �Ÿ�
	Distance[start] = 0;

	priority_queue<pair<int,int>> pq; 
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		//�ּҰŸ��� ���ϹǷ� ->proccess ��ü
		if(Distance[curVertex] <cost)
			continue;
		
		//neighbor �� Ȯ��
		for(auto u: adj[curVertex]){
			int neighbor = u.first;
			int neighborDistance= cost+u.second;

			//�ּ� ��� �߽߰� ������Ʈ
			if(Distance[neighbor]>neighborDistance){
				Distance[neighbor] = neighborDistance;
				//�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� �������� ������
				pq.push(make_pair(-neighborDistance,neighbor));
			}
		}
	}
	return Distance;
}

void ShortestPath(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> V >> E;
	cin>> K;
	
	V++; //������ȣ 1���� ����
	for(int i=1; i<=E ; i++){
		int source, destination, cost;
		cin>> source >> destination >> cost;
		adj[source].push_back(make_pair(destination,cost));
	}

	vector<int> result = dijkstra(K,V);

	for(int i=1; i<V ; i++) {
		if(result[i] == INF)
			cout<<"INF\n";
		else
			cout<<result[i]<<"\n";
	}
	return;
}

/*
	�����
	1) distance ��ü�� �Ѱ������� �޸𸮸� �Ƴ��� �Ǵ�
	2) å �ڵ��� �� Ʋ�ȴ��� �����غ���. -> �׳� pq���� ��������.
	3) ���ͽ�Ʈ�� ���� �˰��򿡼� proccess�� ��ü�ҷ��� �̸� cost�� �������ν� ������ ���ϴ� �˰���
*/