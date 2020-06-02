#include <bits/stdc++.h>
//1504번 문제
//http://melonicedlatte.com/algorithm/2018/08/19/043431.html 참고
using namespace std;
int N, E;
const int MAX = 20000+1;
const int INF = 2147483647;
vector<pair<int,int>> adj[MAX*2];
int Distance[MAX];
priority_queue<pair<int,int>> pq;

int dijkstra(int _start, int _end){
    fill_n(Distance,MAX,INF);
    Distance[_start]=0;
    pq.push(make_pair(0,_start));
    while(!pq.empty()){
        int curCost=-pq.top().first;
        int curVertex=pq.top().second;
        pq.pop();
        
        if(Distance[curVertex]<curCost) continue;

        for(auto u: adj[curVertex]){
            int neighbor= u.first;
            int neighborDistance = curCost+ u.second;
            if(neighborDistance<Distance[neighbor]) {
                Distance[neighbor] = neighborDistance;
                pq.push(make_pair(-neighborDistance,neighbor));
            }
        }
    }
    return Distance[_end];
}
void ShortestPath(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(Distance,MAX,INF);
    //Input
    cin >> N >> E;
    for(int i=1;i<=E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        //양방향 그래프이므로 2번 입력
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    int tempVertex1, tempVertex2;
    cin >> tempVertex1 >> tempVertex2;    

    //디익스트라 알고리즘 6번 수행.
    //start -> temp1 -> temp2 -> N
    int start_temp1 = dijkstra(1,tempVertex1);
    int temp1_temp2 = dijkstra(tempVertex1,tempVertex2);
    int temp2_N = dijkstra(tempVertex2,N);
    int is_possible_1 =0;
    // 가능여부 체크
    if(start_temp1 ==INF || temp1_temp2 == INF || temp2_N == INF) is_possible_1=0;
    else is_possible_1=1;
    //start -> temp2 -> temp1 -> N
    int start_temp2 = dijkstra(1,tempVertex2);
    int temp2_temp1 = dijkstra(tempVertex2,tempVertex1);
    int temp1_N = dijkstra(tempVertex1,N);
    int is_possible_2 = 0;
    //가능여부 체크
    if(start_temp2 == INF || temp2_temp1 ==INF || temp1_N ==INF) is_possible_2=0;
    else is_possible_2=1;

    //출력
    if(is_possible_1 && is_possible_2) {
        cout << min(start_temp1 + temp1_temp2 + temp2_N, start_temp2 + temp2_temp1 + temp1_N);
    }
    else cout<<"-1";
}

/*
    배울점
    1) 1번 노드 -> tempVertex1 -> tempVertex2 -> 2번노드 와
       1번 노드 -> tempVertex2 -> tempVertex1 -> 2번노드 
       를 각각 디익스트라 알고리즘으로 구해야함 (총 6번의 알고리즘 수행)
    2) Graph에선 adj[a]={b,w} (a에서 b로 가는 가중치 w 간선)
       priority queue 에선 {-d,x} (start node에서 x까지 가는데 걸리는 거리 d)
    => 헷갈리지 말자!!
*/
