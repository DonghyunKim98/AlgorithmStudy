#include <bits/stdc++.h>
//11657������
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

    //����-���� �˰���
    fill_n(Distance,MAX,INF);
    Distance[1]=0;
    bool is_negative=false;
    //������ N-1�� ���带 �����ؾ� ������ ���� ����Ŭ�� �ִ��� Ȯ���ϱ� ���� �ѹ� �� �����Ѵ�.
    for (int i=1 ; i<=N+1 ; i++){
        for(auto e: edges){
            int curVertex, neighbor;
            ll weight;
            tie(curVertex,neighbor,weight) = e;
            if (Distance[curVertex] == INF)
                continue;
            //������ ���忡�� �� �پ����� üũ.
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
    �����ؼ�
    1) C<0 : ���� ������ ����. ("���ͽ�Ʈ�� �˰��� ���Ұ���")
    2) -1�� ����ϴ� ��� - ������ ������ ����Ŭ�� �ִ� ��� => ����-���� �˰��� ���

    ������
    1) ����ʰ� => ���� �Ҷ� �������� �ѹ� �� ������ üũ�� min �Լ��� �ϰ� ���� �����ߴ�. �翬�� 2���� ������.
    �׸��� long long���� �ؾ��ϴ� �κ��� �ִ� O(n*m) �̶�� ���� �������
    2) Ʋ�ȴٰ� �� => Distance[curVertex] �� INF�϶��� ó���� �����ߴ�.
*/