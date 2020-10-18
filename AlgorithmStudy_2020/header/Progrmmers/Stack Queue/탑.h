#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    //{height,index}
    stack <pair<int,int>> s;
    for (int i = 0; i < heights.size();i++)
        s.push(make_pair(heights[i],i+1));

    for (int i = heights.size() - 1; i >= 0; i--) {
        //현재 있는 위치의 것을 꺼냄 
        int current_top = s.top().first;
        s.pop();
        stack<pair<int,int>> temp;
        //만약 찾았다면 꺼내지않음! -> for문을 처음 들어올때 꺼낼 것.
        while (!s.empty()) {
            if (s.top().first > current_top) {
                answer[i] = s.top().second;
                break;
            }
            else {
                temp.push(s.top());
                s.pop();
            }
        }
        if (s.empty()) answer[i] = 0;

        //temp에 있던 친구들 다시 넣음
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    return answer;
}

/*
    1. 발사한 신호는 보낸 탑보다 높은 탑에서만 수신
    2. 한 번 수신된 신호는 다른 탑으로 송신하지 않음
    3. 신호 발사는 왼쪽으로 송신 (제일 먼저 왼쪽에 있고  탑이 송신을 받음-> 인덱스가 큰 순서 )
    4. index는 1부터 시작.

    [6,9,5,7,4]
*/