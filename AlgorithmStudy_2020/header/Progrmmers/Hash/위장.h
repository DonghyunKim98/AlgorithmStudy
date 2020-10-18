#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<string>> clothes) {
    int answer=1;
    map<string, int> m;
    for (auto u : clothes) {
        if (m.count(u.at(1))==0) m.insert(make_pair(u.at(1), 1));
        else m[u.at(1)]++;
    }
    for (auto u : m) 
        answer *= (u.second+1);
    return answer-1;
}

/*
    �տ� �ִ� ���� value, �ڿ� �ִ� ���� key.

    map ���� key���� �ִ��� �������� m.count�� �̿��ؼ� Ȯ���غ���
*/