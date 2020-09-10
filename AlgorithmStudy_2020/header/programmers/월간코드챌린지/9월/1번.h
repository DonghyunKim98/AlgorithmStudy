#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    //두 수의 최대 합은 200
    bool arr[201];
    memset(arr, false, sizeof(arr));
    for (int i = 0; i < (int)numbers.size(); i++) {
        for (int j = i + 1; j < (int)numbers.size(); j++) {
            arr[numbers[i]+numbers[j]] = true;
        }
    }
    for (int i = 0; i <= 200; i++)
        if (arr[i]) answer.push_back(i);
    return answer;
}