#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
    int answer = 0, cnt=0;
    stack<bool> s;
    //�ϴ� 1���� push
    s.push(true);
    cnt++;
    for (int i = 1; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            s.push(true);
            cnt++;
        }
        else {
            //�ٷ� �������� ( => ������
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
    () �� �ٷ� ������ ������
    () �� �������� ������ �踷���
    => () �� ������ �տ� '('�� ������ŭ �߶����.
*/