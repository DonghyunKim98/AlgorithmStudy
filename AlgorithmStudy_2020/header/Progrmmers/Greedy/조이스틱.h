#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    //�� ó���� �������� answer++�� ���� ����
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

        //�������� ������ ���������� ������ ����
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
        //�������� �ʴ´ٸ� ��δ� A��� �Ҹ��̹Ƿ� Ż�� 
        if(!is_moving) break;
    }
    return answer;
}