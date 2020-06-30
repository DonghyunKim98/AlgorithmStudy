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
    앞에 있는 것이 value, 뒤에 있는 것이 key.

    map 에서 key값이 있는지 없는지는 m.count를 이용해서 확인해보자
*/