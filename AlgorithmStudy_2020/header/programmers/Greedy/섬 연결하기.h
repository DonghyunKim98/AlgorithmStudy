#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 1;
int d[MAX];
int find(int node) {
    //부모가 자기자신이면 현재 노드가 최상위 부모
    if (node == d[node]) return node;
    //아니라면 최상위 부모를 찾음
    else return d[node] = find(d[node]);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //d[i]에는 부모를 담음. 맨 처음엔 모든 노드가 곧 부모(컴포넌트) 처리
    for (int i = 0; i < n; i++)
        d[i] = i;

    //간선의 가중치를 기준으로 오름차순 정렬 => 크루스칼 알고리즘
    sort(costs.begin(), costs.end(),cmp);

    //모든 간선을 검사
    for (int i = 0; i < costs.size(); i++) {
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];

        //start와 end가 연결이 아직 안되어 있다면
        if (start != end) {
            //start의 부모를 end로 설정
            d[start] = end;
            //간선의 가중치를 결과에 더해줌
            answer += cost;
        }
        //연결되어 있다면 아무런 행동도 하지 않음.
    }
    return answer;
}

/*
    문제 해설 
    =>최소 비용 , 모든 섬 통행 가능, 다리 여러번 건널 수 있음, 순서가 바뀌어도 같은 연결(양방향 간선&가중치 같음)
    => 최소 스패닝 트리(Minimum Spanning Tree)를 푸는 문제. 
    => 크루스칼 알고리즘 이용
    => 책에선 union-find 구조로 집합을 관리.
    알고리즘 포인트
    => 여기선 각각의 컴포넌트도 트리라는것에 입각해서 '각각의 트리의 부모를 배열에 담아두고'
    => 부모가 같다 == 연결 / 부모가 같지 않다 ==아직 연결 안됨 으로 처리
    (책에선  if(!same(a,b)) unite(a,b); 로 처리 했음)
*/
