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
     정해진 총액 안에서 가능한 한 최대의 총 예산을 책정
     1. ALL possible -> 그냥 다 더해.
     2. All not possible -> 상한액을 정하고 상한액을 넘기면 상한액만 예산 배정
     가능한 한 최대의 총 예산이므로, 상한액은 최대한 높게 잡아야 함.
*/