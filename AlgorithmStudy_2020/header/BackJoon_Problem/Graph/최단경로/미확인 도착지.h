#include <bits/stdc++.h>
//9370번 문제
//https://zoomkoding.github.io/%EB%B0%B1%EC%A4%80/2019/07/31/baekjoon-9370.html 참고
using namespace std;
const int MAX = 2000+1;
const int INF = 987654321;
int T;
int n,m,t;
int start,g,h;
vector<pair<int,int>> adj[MAX*2];
priority_queue<pair<int,int>> pq;
int Distance[MAX];
int Destination[100+1];

void clear(int _count){
    fill_n(Distance,MAX,INF);
    fill_n(Destination,100+1,NULL);
    for(int i=1;i<=_count;i++){
        adj[i].clear();
    }
}

int dijkstra(int _start, int _end){
    fill_n(Distance,MAX,INF);
    Distance[_start]=0;
    pq.push(make_pair(0,_start));
    while(!pq.empty()){
        int curCost = -pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();
        if(curCost>Distance[curVertex]) continue;
        for(auto u: adj[curVertex]){
            int neighbor = u.first;
            int neighborDistance =u.second+curCost;
            if(neighborDistance<Distance[neighbor]){
                Distance[neighbor]=neighborDistance;
                pq.push(make_pair(-neighborDistance,neighbor));   
            }
        }
    }
    return Distance[_end];
}

void UnConfirmedDestination(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T>0){
        //input
        cin >> n >> m >> t;
        cin >> start >> g >> h;
        int g_h;
        for(int i=1 ; i<=m ; i++){
            int a,b,d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b,d));
            adj[b].push_back(make_pair(a,d));
            if( (a==g && b==h) || (a==h && b==g) ) g_h=d;
        }
        for(int k=1; k<=t ; k++){
            cin >> Destination[k];
        }
        //디익스트라 알고리즘 진행
        int* start_destination = new int[100+1];
        int* g_destination = new int[100+1];
        int* h_destination = new int[100+1];
        int start_g, start_h;
        //start->destination , start->g , start->h, g->destination, h->destination 를 구해준다.
        for(int j=1; j<=t ; j++){
            start_destination[j] = dijkstra(start, Destination[j]);
            g_destination[j] = dijkstra(g,Destination[j]);
            h_destination[j] = dijkstra(h,Destination[j]);
        }
        start_g = dijkstra(start,g);
        start_h = dijkstra(start,h);
        //비교후 sorting
        vector <int> answer ;
        for (int i = 1; i <= t; i++)
        {
            if(start_destination[i] == start_g + g_h + h_destination[i]){
                answer.push_back(Destination[i]);
            }
            else if(start_destination[i] == start_h + g_h + g_destination[i]){
                answer.push_back(Destination[i]);
            }
        }
        sort(answer.begin(),answer.end());
        //output
        for(auto u: answer){
            cout<<u<<" ";
        }
        cout<<"\n";
        //비워주고 다음 test 진행
        clear(n*2);
        T--;
    }
}

/*
    1. vector랑 array 의 index에 대한 고려!
       array를 1부터 시작한다고 해도 vector는 0부터 시작함.
       1부터 array를 채워넣는 Graph의 경우에 조심할 것.
    
    *문제점
    1) 주어진 그림에서 start_g (2번노드에서 3번노드) 의 최단거리는 2->1->3 이다. 이렇게되면 당연히도 "중복"된다. (중간에 g_h를 겪기 때문이다.)
    -> 해결방안: 도둑들은 무조건 최단거리로 움직인다. 최단거리 내에서 g랑 h를 거치는지를 확인해야한다. (구현이 잘못됨)
    -> 이 역시 잘못된게 디익스트라 알고리즘은 알고리즘 내부에서 특정 노드를 거쳤는지 안 거쳤는지를 알 수가 없다.
    -> start->g->h->x나 start->h->g->x 값이 s->x와 같다면 이 친구는 벡터에 넣어서 sort해준 후 출력한다. (wow... 전혀 생각도 못했다. 처음 구현이 오히려 좀더 풀이에 적합했다.) 

    2) 수학 과외할때 "무엇을 구하라" 에 대해서 그렇게 내가 강조를 했으면서 이 개 똥멍청이는 왜 최단거리 알고리즘에서 반드시 최단거리를 구하라고 생각했지??
*/
