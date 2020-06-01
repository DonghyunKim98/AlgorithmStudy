#include <bits/stdc++.h>
//1753번 문제
//다익스트라 알고리즘 이용
//https://jaimemin.tistory.com/555 참고
using namespace std;
const int MAX = 20000 + 1;
const int INF = 2147483647;
int V, E, K;
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int,int>> pq;
bool proccess[MAX]={false,};
int Distance[MAX];

void ShortestPath() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fill_n(Distance,MAX,INF);
	cin >> V >> E;
	cin >> K;
	for(int i=1 ; i<=E; i++){
		int temp1, temp2, temp3;
		cin>>temp1>>temp2>>temp3;
		adj[temp1].push_back({temp2,temp3});
	}

	//디익스트라 알고리즘 
	Distance[K]=0;
	pq.push({0,K});
	while(!pq.empty()){
		int a=pq.top().first;
		pq.pop();
		if(proccess[a]) continue;
		proccess[a]=true;
		for(auto u: adj[a]){
			int b=u.first, w=u.second;
			if(Distance[b]>Distance[a]+w){
				Distance[b]=Distance[a]+w;
				pq.push({-Distance[b],b});
			}
		}
	}

	//출력
	for(int i=1; i<=V; i++){
		if(Distance[i]==INF) cout<<"INF\n";
		else cout<<Distance[i]<<"\n";
	}
}