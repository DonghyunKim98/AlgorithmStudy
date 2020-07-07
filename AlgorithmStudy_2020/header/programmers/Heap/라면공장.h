#include <bits/stdc++.h>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    //Max heap
    priority_queue<int, vector<int>, less<int>> pq;
    int index = 0;
    for (int i = 0; i < k; i++) {
        if (dates[index] == i) {
            pq.push(supplies[index]);
            index++;
        }
        if (stock == 0) {
            stock = pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}

/*
    pq에 넣고 stock이 떨어질때마다 그동안 공급받았던 것중 큰걸 쓴다(answer을 1개 늘린다)의 개념....!!
*/
