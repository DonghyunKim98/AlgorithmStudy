#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    string answer = "";
    for (int i = 0; i<=int(completion.size()); i++) {
        if (i == completion.size()) {
            answer = participant.at(i);
            break;
        }
        else if (participant.at(i) != completion.at(i)) {
            answer = participant.at(i);
            break;
        }
    }
    return answer;
}