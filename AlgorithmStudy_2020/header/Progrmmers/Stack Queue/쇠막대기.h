#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
    int answer = 0, cnt=0;
    stack<bool> s;
    //일단 1개는 push
    s.push(true);
    cnt++;
    for (int i = 1; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            s.push(true);
            cnt++;
        }
        else {
            //바로 직전항이 ( => 레이저
            if (arrangement[i - 1] == '(') {
                s.pop();
                cnt--;
                answer += s.size();
            }
            else 
                s.pop();
        }
    }
    answer += cnt;
    return answer;
}


/*
    () 가 바로 나오면 레이저
    () 가 떨어져서 나오면 쇠막대기
    => () 가 나오면 앞에 '('의 개수만큼 잘라버려.
*/