#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue <pair<int,int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i],i));
    }
    int answer = 1;
    while (true) {
        //우선순위가 일치하면 출력
        if (q.front().first == pq.top()) {
            //맨 앞에 있는 element가 내가 원하는 것.
            if (location == q.front().second) return answer;
            //내가 원하는 것이 아니라면 지우기만 해주고 answer을 늘려줌
            else {
                q.pop();
                pq.pop();
                answer++;
            }
        }
        //우선순위가 일치하지 않으면 q에 있는 것을 맨 뒤로 보냄
        else {
            q.push(q.front());
            q.pop();
        }
    }
}

/*
    백준 1966(프린터 큐) 문제와 비교
*/