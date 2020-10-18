#include <bits/stdc++.h>
//9370�� ����
//https://zoomkoding.github.io/%EB%B0%B1%EC%A4%80/2019/07/31/baekjoon-9370.html ����
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
        //���ͽ�Ʈ�� �˰��� ����
        int* start_destination = new int[100+1];
        int* g_destination = new int[100+1];
        int* h_destination = new int[100+1];
        int start_g, start_h;
        //start->destination , start->g , start->h, g->destination, h->destination �� �����ش�.
        for(int j=1; j<=t ; j++){
            start_destination[j] = dijkstra(start, Destination[j]);
            g_destination[j] = dijkstra(g,Destination[j]);
            h_destination[j] = dijkstra(h,Destination[j]);
        }
        start_g = dijkstra(start,g);
        start_h = dijkstra(start,h);
        //���� sorting
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
        //����ְ� ���� test ����
        clear(n*2);
        T--;
    }
}

/*
    1. vector�� array �� index�� ���� ���!
       array�� 1���� �����Ѵٰ� �ص� vector�� 0���� ������.
       1���� array�� ä���ִ� Graph�� ��쿡 ������ ��.
    
    *������
    1) �־��� �׸����� start_g (2����忡�� 3�����) �� �ִܰŸ��� 2->1->3 �̴�. �̷��ԵǸ� �翬���� "�ߺ�"�ȴ�. (�߰��� g_h�� �ޱ� �����̴�.)
    -> �ذ���: ���ϵ��� ������ �ִܰŸ��� �����δ�. �ִܰŸ� ������ g�� h�� ��ġ������ Ȯ���ؾ��Ѵ�. (������ �߸���)
    -> �� ���� �߸��Ȱ� ���ͽ�Ʈ�� �˰����� �˰��� ���ο��� Ư�� ��带 ���ƴ��� �� ���ƴ����� �� ���� ����.
    -> start->g->h->x�� start->h->g->x ���� s->x�� ���ٸ� �� ģ���� ���Ϳ� �־ sort���� �� ����Ѵ�. (wow... ���� ������ ���ߴ�. ó�� ������ ������ ���� Ǯ�̿� �����ߴ�.) 

    2) ���� �����Ҷ� "������ ���϶�" �� ���ؼ� �׷��� ���� ������ �����鼭 �� �� �˸�û�̴� �� �ִܰŸ� �˰��򿡼� �ݵ�� �ִܰŸ��� ���϶�� ��������??
*/
