#include <bits/stdc++.h>
//10217번 문제
//https://kyunstudio.tistory.com/160 참고
using namespace std;
const int INF = 987654321;
const int MAX = 100+1;
const int MAX_COST = 10000 +1;
int T;
int N, M, K;
//adj[startNode] = {EndNode, weight, cost}
vector <pair<int, pair<int,int>>> adj[MAX];
//Distance
int Distance [MAX][MAX_COST];

void clear(){
    for (int i = 1; i < MAX; i++) {
        while (!adj[i].empty()) {
            adj[i].pop_back();
        }
    }
}

void dikjstra(){

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            Distance [i][j] =INF;
        }
    }
    //pq => (-time,{cost,nextVertex})
    priority_queue <pair<int,pair<int,int>>> pq;
    Distance[1][0]=0;
    pq.push(make_pair(0,make_pair(0,1)));
    while(!pq.empty()){
        int curVertex = pq.top().second.second;
        int curCost = pq.top().second.first;
        int curTime = -pq.top().first;
        pq.pop();

        if(Distance[curVertex][curCost] < curTime) continue;
        for(auto u: adj[curVertex]){
            int nextVertex = u.first;
            int nextCost = u.second.first +curCost;
            int nextTime = u.second.second + curTime;
            //최대 비용을 초과하는 가격이라면 패스 => 배열의 index 상으로도 패스해야함
            if (nextCost > MAX_COST) continue;
            if(Distance[nextVertex][nextCost] > nextTime){
                Distance[nextVertex][nextCost] = nextTime;
                pq.push(make_pair(-nextTime,make_pair(nextCost,nextVertex)));
            }
        }
    }

    int answer = INF;
    for(int i=1 ; i<= M ;i++){
        answer = min(answer, Distance[N][i]);
    }

    if(answer==INF){
        cout<<"Poor KCM\n"; 
    }
    else
        cout<< answer <<"\n";
}

void KCM_Travel(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T > 0) {
        //input 
        cin >> N >> M >> K;
        for(int i=1; i<=K ; i++){
            int StartVertex, EndVertex, cost, weight;
            cin >> StartVertex >> EndVertex >> cost >> weight ;
            adj[StartVertex].push_back(make_pair(EndVertex,make_pair(cost,weight)));
        }   

        //dikjstra algorithm
        dikjstra();
        T--;
        clear();
    }
}


/*
    1) 문제 구현
    => 공항에 도착할때 "얼마를 쓰고 도착했는가" 를 구별하자(배열의 차원을 하나 더 늘려주면 됨)
    => DFS_BFS 에서 "벽 부수고 이동하기" 참고하면 좋음
    => 마지막에 "cost" 안에 들어왔으면서 최소비용을 알아야 하기 때문에, Distance[N] 의 모든 값을 비교해본다.
*/