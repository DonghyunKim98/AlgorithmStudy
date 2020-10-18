#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) 
        pq.push(scoville[i]);
    
    while (pq.size()!=1 && pq.top()<K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        answer++;
        pq.push(first + second * 2);
    }
    if (pq.size()==1&&pq.top()<K) return -1;
    else return answer;
}