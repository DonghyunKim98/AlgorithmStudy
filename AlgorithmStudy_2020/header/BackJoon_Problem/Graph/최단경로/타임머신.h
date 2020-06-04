#include <bits/stdc++.h>
//11657번문제
typedef long long ll;
using namespace std;
const int MAX = 500+1;
const int INF = 987654321;

int N, M;
vector<tuple<int,int,ll>> edges;
ll Distance[MAX];

void TimeMachine(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //Input
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int A,B;
        ll C;
        cin >> A >> B >> C;
        edges.push_back(make_tuple(A,B,C));
    }

    //벨만-포드 알고리즘
    fill_n(Distance,MAX,INF);
    Distance[1]=0;
    bool is_negative=false;
    //원래는 N-1번 라운드를 진행해야 하지만 음수 사이클이 있는지 확인하기 위해 한번 더 진행한다.
    for (int i=1 ; i<=N+1 ; i++){
        for(auto e: edges){
            int curVertex, neighbor;
            ll weight;
            tie(curVertex,neighbor,weight) = e;
            if (Distance[curVertex] == INF)
                continue;
            //마지막 라운드에서 더 줄어드는지 체크.
            if (i == N && Distance[neighbor] > Distance[curVertex] + weight)
            {
                is_negative = true;
            }
            Distance[neighbor] = min(Distance[neighbor],Distance[curVertex]+weight);
        }
    }
    //output
    if(!is_negative){
        for(int i=2; i<=N; i++){
            if(Distance[i]==INF) cout<<"-1\n";
            else cout<<Distance[i]<<"\n";
        }
    }
    else{
        cout<<"-1";
    }

}


/*
    문제해설
    1) C<0 : 음수 간선이 존재. ("디익스트라 알고리즘 사용불가능")
    2) -1을 출력하는 경우 - 음수를 포함한 사이클이 있는 경우 => 벨만-포드 알고리즘 사용

    문제점
    1) 출력초과 => 구현 할때 마지막에 한번 더 도는지 체크를 min 함수를 하고 나서 진행했다. 당연히 2개가 같겠지.
    그리고 long long으로 해야하는 부분이 있다 O(n*m) 이라는 것을 명심하자
    2) 틀렸다고 뜸 => Distance[curVertex] 가 INF일때의 처리를 간과했다.
*/