#include<bits/stdc++.h>
using namespace std;
const int MAX = 300;
vector<int> col_one_cnt;
vector<int> vc;
int answer = 0;
int mod = 10000000 + 7;
void DFS(int idx) {
    if (idx == col_one_cnt.size()) {

    }
    
    DFS(idx + 1);
}
int solution(vector<vector<int>> a) {
    int answer = 0;
    //a행에 있는 1의 개수를 샘

    for (int i = 0; i < a[0].size(); i++) {
        int temp = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j][i] == 1) temp++;
        }
        col_one_cnt.push_back(temp);
    }
    DFS(0);

    return answer;
}


/*
    총 n개의 행
    1열 => a1 개
    2열 => a2 개
    3열 => a3 개
    ...
    k열 => ak 개

    1열 -> a1만큼 1이 있음
    2열 -> 
*/