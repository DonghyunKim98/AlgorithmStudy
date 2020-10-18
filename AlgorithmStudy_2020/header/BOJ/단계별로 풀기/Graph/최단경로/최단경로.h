#include <bits/stdc++.h>
//1753번 문제
//다익스트라 알고리즘 이용
//https://jaimemin.tistory.com/555 참고
using namespace std;
const int MAX = 20000 + 1;
const int INF = 2147483647;
int V, E, K;
vector<pair<int, int>> adj[MAX];

vector<int> dijkstra(int start, int vertex){
	vector<int> Distance(vertex,INF); //start를 기준으로 거리
	Distance[start] = 0;

	priority_queue<pair<int,int>> pq; 
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		//최소거리를 원하므로 ->proccess 대체
		if(Distance[curVertex] <cost)
			continue;
		
		//neighbor 다 확인
		for(auto u: adj[curVertex]){
			int neighbor = u.first;
			int neighborDistance= cost+u.second;

			//최소 경로 발견시 업데이트
			if(Distance[neighbor]>neighborDistance){
				Distance[neighbor] = neighborDistance;
				//거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내기
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
	
	V++; //정점번호 1부터 시작
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
	배울점
	1) distance 자체를 넘겨줌으로 메모리를 아끼는 판단
	2) 책 코딩이 왜 틀렸는지 생각해보자. -> 그냥 pq에서 변수착각.
	3) 디익스트라 내부 알고리즘에서 proccess를 대체할려고 미리 cost를 꺼냄으로써 기존과 비교하는 알고리즘
*/