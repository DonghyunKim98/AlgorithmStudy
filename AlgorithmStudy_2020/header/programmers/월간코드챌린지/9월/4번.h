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
    //a�࿡ �ִ� 1�� ������ ��

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
    �� n���� ��
    1�� => a1 ��
    2�� => a2 ��
    3�� => a3 ��
    ...
    k�� => ak ��

    1�� -> a1��ŭ 1�� ����
    2�� -> 
*/