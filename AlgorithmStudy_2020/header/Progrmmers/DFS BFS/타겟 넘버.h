#include <bits/stdc++.h>
using namespace std;
vector<int> vc;
int target2;
int cnt = 0;
void DFS(int idx,int value) {
    //������ ������ ����ϰ� target�� ��ġ�ϸ� cnt ����
    if (idx == vc.size()) {
        if (value == target2) cnt++;
        return;
    }
    else {
        //plus opearation
        value += vc[idx];
        DFS(idx + 1, value);
        //backTracking
        value -= vc[idx];
        //minus operation
        value -= vc[idx];
        DFS(idx + 1, value);
        //backTracking
        value += vc[idx];
    }
}

int solution(vector<int> numbers, int target) {
    target2 = target;
    for (int i = 0; i < numbers.size(); i++)
        vc.push_back(numbers[i]);
    DFS(0, 0);
    return cnt;
}