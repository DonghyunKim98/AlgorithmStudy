#include <bits/stdc++.h>
using namespace std;
int answer = 0, column = 0;
vector<string> combination;

bool cmp(string& a, string& b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}
// 모든 조합을 만든다.
void DFS(int k = 0, string str = "") {
    for (int i = k; i < column; i++) {
        str += to_string(i);
        combination.push_back(str);
        DFS(i + 1, str);
        str = str.substr(0, str.length() - 1);
    }
}
// uniqueness를 판단하는 곳
bool subset(vector<vector<string>>& relation, string com) {
    map<string, int> candidate;
    for (int i = 0; i < relation.size(); i++) {
        string temp = "";
        for (int k = 0; k < com.length(); k++) {
            int colIdx = com[k] - '0';
            temp += relation[i][colIdx];
        }
        if (candidate[temp]) return false;
        candidate[temp]++;
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    column = relation[0].size();
    DFS();
    sort(combination.begin(), combination.end(),cmp);
    for (int i = 0; i < combination.size(); i++) {
        if (subset(relation, combination[i])) {
            // 미리 subset에 해당하는 것들을 지워준다
            string temp = combination[i];
            for (int j = combination.size() - 1; j >= i; j--) {
                bool check = true;
                for (auto u : temp) {
                    if (combination[j].find(u) == string::npos) {
                        check = false;
                        break;
                    }
                }
                if (check) combination.erase(combination.begin() + j);
            }
            i--; answer++;
        }
    }
    return answer;
}