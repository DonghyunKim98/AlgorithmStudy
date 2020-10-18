#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> budgets, int M) {
    sort(budgets.begin(), budgets.end());
    long long int begin = 0, end=budgets[budgets.size()-1];
    while (begin <= end) {
        long long int mid = (begin + end) / 2;
        long long int begin_mid_total = 0, mid_end_total=0;
        int idx = 0;
        for (idx = 0; budgets[idx] < mid; idx++) 
            begin_mid_total += budgets[idx];
        mid_end_total = (budgets.size() - idx) * mid;
        if (begin_mid_total + mid_end_total <= M) 
            begin = mid + 1;
        else end = mid - 1;
    }
    return end;
}

/*
     ������ �Ѿ� �ȿ��� ������ �� �ִ��� �� ������ å��
     1. ALL possible -> �׳� �� ����.
     2. All not possible -> ���Ѿ��� ���ϰ� ���Ѿ��� �ѱ�� ���Ѿ׸� ���� ����
     ������ �� �ִ��� �� �����̹Ƿ�, ���Ѿ��� �ִ��� ���� ��ƾ� ��.
*/