#include <bits/stdc++.h>
//9370번 문제
using namespace std;
const int MAX = 2000+1;
const int INF = 987654321;
int T;
int n,m,t;
int start,g,h;
vector<pair<int,int>> adj[MAX*2];
priority_queue<pair<int,int>> pq;
int Distance[MAX];
vector<int> Destination;

void clear(int _count){
    fill_n(Distance,INF,MAX);
    Destination.clear();
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
            int x;
            cin >> x;
            Destination.push_back(x);
        }
        //디익스트라 알고리즘 진행
        int start_g, start_h; 
        vector<int> g_destination;
        vector<int> h_destination;
        int* is_possible_From_g = new int[t+1];
        int* is_possible_From_h = new int[t+1];

        start_g = dijkstra(start,g);
        start_h = dijkstra(start,h);
        for(int j=1; j<=t ; j++){
            g_destination.push_back(dijkstra(g,Destination[j]));
            h_destination.push_back(dijkstra(h,Destination[j]));
            cout<<"여기까진 왔다"<<endl;
        }
        // INF 검사
        for(int j=1; j<=t ; j++){
            if (start_g == INF || g_destination[j] == INF)
                is_possible_From_g[j] = 0;
            else is_possible_From_g[j] = 1;

            if (start_h ==INF || h_destination[j] == INF)
                is_possible_From_h[j] =0;
            else is_possible_From_h[j] =1;
        }

        //sorting
        vector <int> answer ;
        for (int i = 1; i <= t; i++)
        {
            if (is_possible_From_g[i])
            {
                if (is_possible_From_h[i])
                    answer.push_back(min(start_g + g_destination[i] + g_h, start_h + h_destination[i] + g_h));
                else
                {
                    answer.push_back(start_g+g_destination[i]+g_h);
                }
            }
            else
            {
                if(is_possible_From_h[i])
                    answer.push_back(start_h+h_destination[i]+g_h);
            }
        }
        sort(answer.begin(),answer.end());
        //출력
        for(int i=1; i<=t ;i++){
            cout<<answer[i];
        }
        //비워주고 다음 test 진행
        clear(n*2);
        T--;
    }
}