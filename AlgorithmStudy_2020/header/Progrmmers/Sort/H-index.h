#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
    for (int idx = 0; idx < citations.size(); idx++) {
        //���� ���� �ο������ �׵����� �ο�� �� ���� �� ũ�ų� ������
        if (citations[idx] <= idx + 1) {
                //���� ���� ���
                if (citations[idx]==idx+1) return idx+1;
                //���� ���� ���
                else return idx;    
        }
    }

}