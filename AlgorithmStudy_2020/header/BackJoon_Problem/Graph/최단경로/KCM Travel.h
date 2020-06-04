#include <bits/stdc++.h>
//10217�� ����
//https://kyunstudio.tistory.com/160 ����
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
            //�ִ� ����� �ʰ��ϴ� �����̶�� �н� => �迭�� index �����ε� �н��ؾ���
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
    1) ���� ����
    => ���׿� �����Ҷ� "�󸶸� ���� �����ߴ°�" �� ��������(�迭�� ������ �ϳ� �� �÷��ָ� ��)
    => DFS_BFS ���� "�� �μ��� �̵��ϱ�" �����ϸ� ����
    => �������� "cost" �ȿ� �������鼭 �ּҺ���� �˾ƾ� �ϱ� ������, Distance[N] �� ��� ���� ���غ���.
*/