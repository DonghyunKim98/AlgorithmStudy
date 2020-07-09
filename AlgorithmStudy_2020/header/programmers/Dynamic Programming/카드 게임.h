#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    while (!left.empty() && !right.empty()) {
        if (left.front() > right.front()) {
            answer += right.front();
            right.erase(right.begin());
        }
        else if (left.front() < right.front()) {
            left.erase(left.begin());
        }
        else {
            right.erase(right.begin());
            left.erase(left.begin());
        }
    }
    return answer;
}