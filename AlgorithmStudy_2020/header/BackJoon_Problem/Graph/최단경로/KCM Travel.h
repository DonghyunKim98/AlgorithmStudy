#include <bits/stdc++.h>
//10217¹ø ¹®Á¦
using namespace std;
const int MAX = 100+1;
int T;
int N, M, K;
//adj[startNode] = {EndNode, weight, cost}
vector <tuple<int,int,int>> adj[MAX];

void dikjstra(){

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
            adj[StartVertex].push_back(make_tuple(EndVertex,weight,cost));
        }   

        //dikjstra algorithm
        

        //output
        T--;
    }
}