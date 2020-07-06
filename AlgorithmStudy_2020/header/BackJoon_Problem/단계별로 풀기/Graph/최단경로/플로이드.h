#include <bits/stdc++.h>
//11404번 문제
using namespace std;
const int MAX = 100 + 1;
const int INF = 987654321;
int n , m ;
int adj[MAX][MAX];
int dist[MAX][MAX];

void Floyd(){
    //Input
    cin>> n >> m;
    fill(&adj[0][0],&adj[MAX-1][MAX],0);
    for (int i = 1; i <= m; i++)
    {
        int startVertex, endVertex, weight;
        cin >> startVertex >> endVertex >> weight;
        if (adj[startVertex][endVertex])
            adj[startVertex][endVertex] = min(weight, adj[startVertex][endVertex]);
        else
            adj[startVertex][endVertex] = weight;
    }
    //플로이드-워셜 알고리즘
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }

    for(int k=1; k<=n ; k++){
        for(int i=1; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    //Output
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            if(dist[i][j] == INF) cout <<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

/*
    문제점
    1) 두 정점을 연결하는 노선이 한 개가 아닐수 있다는 점.
       -> 입력받을 때 최소 값으로 비교해서 받자.
*/