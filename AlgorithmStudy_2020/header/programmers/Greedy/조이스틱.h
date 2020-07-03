#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    //맨 처음에 들어왔을때 answer++에 대한 방지
    int answer = -1;
    int cnt = 0;
    int idx = 0;
    while (true) {
        answer += min(name[idx] - 'A','Z'-name[idx]+1);
        answer++;
        name[idx] = 'A';
        cnt++;
        if (cnt == name.length())
            break;

        //왼쪽으로 갈건지 오른쪽으로 갈건지 정함
        bool is_moving=false;
        int left_idx = idx, right_idx = idx;
        for (int i = 0; i <= name.length() / 2; i++) {
            if (left_idx == 0) left_idx = name.length() - 1;
            else left_idx--;
            if (right_idx == name.length() - 1) right_idx = 0;
            else right_idx++;
            if (name[right_idx] != 'A') {
                is_moving = true;
                if (idx == name.length() - 1) idx = 0;
                else idx++;
                break;
            }
            else if (name[left_idx] != 'A') {
                is_moving = true;
                if (idx == 0) idx = name.length() - 1;
                else idx--;
                break;
            }
        }
        //움직이지 않는다면 모두다 A라는 소리이므로 탈출 
        if(!is_moving) break;
    }
    return answer;
}