#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector <pair<int, int>> vc;
    for (int i = 0; i < progresses.size(); i++) 
        vc.push_back(make_pair(progresses[i], speeds[i]));

    while (!vc.empty()) {
        //하루가 경과했으므로 speed만큼 추가.
        for (int i = 0; i < vc.size(); i++)
            vc[i].first += vc[i].second;
        int cnt=0;
        while (true) {
            if (!vc.empty()) {
                if (vc[0].first >= 100) {
                    cnt++;
                    vc.erase(vc.begin());
                }
                else break;
            }
            else break;
        }
        if(cnt!=0)
            answer.push_back(cnt);
    }
    return answer;
}