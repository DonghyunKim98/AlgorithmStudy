#include <bits/stdc++.h>
//1956번 문제
using namespace std;
const int INF = 987654321;
const int MAX = 400+1;
int V , E ;
int dist[MAX][MAX];
int adj[MAX][MAX];

void Execrise(){
    //setting
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(&adj[0][0],&adj[MAX-1][MAX],0);
    //input
    cin >> V >> E;
    for(int i=1 ; i<= E; i++){
        int StartNode , EndNode, weight ;
        cin>> StartNode >> EndNode >> weight ;
        adj[StartNode][EndNode] =weight;
    }

    //플로이드-워셜 알고리즘
    for(int i=1 ; i<= V ; i++){
        for(int j=1 ; j<= V ; j++){
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }

    for(int k=1 ; k<=V ; k++){
        for(int i=1 ; i<= V ; i++){
            for(int j=1 ; j<=V ; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // Cycle confrimation & output
    int answer=0;
    for(int i=1 ;i<=V ; i++){
        for(int j=1 ; j<=V ; j++){
            //자기 자신은 제외
            if(i == j) continue;
            if((dist[i][j] && dist[j][i]) && (dist[i][j] != INF && dist[j][i] != INF)) {
                if(answer==0) 
                    answer=dist[i][j] +dist[j][i];
                else 
                    answer=min(answer,dist[i][j]+dist[j][i]);
            }
        }
    }
    
    if(answer) cout<<answer;
    else cout<<"-1";
}

/*
    구현 ) 사이클의 길이가 제일 짧은 것 => 플로이드-워셜 알고리즘을 이용해서 dist[i][j] + dist[j][i] 중 제일 짧은 것을 나타내주면 될것같다.

    문제점) 1. INF 처리!! INF처리에 잘해보장
*/