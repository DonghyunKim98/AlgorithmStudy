#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input) {
    vector<string> ret;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ' ')) ret.push_back(temp);
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    for (int i = 0; i < record.size(); i++) {
        vector<string> curRecord = split(record[i]);
        if (curRecord[0] == "Enter"|| curRecord[0]=="Change") {
            user[curRecord[1]] = curRecord[2];
        }
    }
    for (int i = 0; i < record.size(); i++) {
        vector<string> curRecord = split(record[i]);
        if (curRecord[0] == "Enter") {
            answer.push_back(user[curRecord[1]] + "님이 들어왔습니다.");
        }
        else if (curRecord[0] == "Leave") {
            answer.push_back(user[curRecord[1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}