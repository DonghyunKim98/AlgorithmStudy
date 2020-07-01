#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
    for (int idx = 0; idx < citations.size(); idx++) {
        //현재 논문의 인용수보다 그동안의 인용된 논문 수가 더 크거나 같으면
        if (citations[idx] <= idx + 1) {
                //현재 개수 출력
                if (citations[idx]==idx+1) return idx+1;
                //이전 개수 출력
                else return idx;    
        }
    }

}