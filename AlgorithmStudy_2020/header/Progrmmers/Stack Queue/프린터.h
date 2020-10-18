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
        //�켱������ ��ġ�ϸ� ���
        if (q.front().first == pq.top()) {
            //�� �տ� �ִ� element�� ���� ���ϴ� ��.
            if (location == q.front().second) return answer;
            //���� ���ϴ� ���� �ƴ϶�� ����⸸ ���ְ� answer�� �÷���
            else {
                q.pop();
                pq.pop();
                answer++;
            }
        }
        //�켱������ ��ġ���� ������ q�� �ִ� ���� �� �ڷ� ����
        else {
            q.push(q.front());
            q.pop();
        }
    }
}

/*
    ���� 1966(������ ť) ������ ��
*/