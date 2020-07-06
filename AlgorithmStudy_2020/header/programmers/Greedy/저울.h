#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(),weight.end());
    if (weight[0] == 1) {
        int end = 1;
        for (int i = 1; i < weight.size(); i++) {
            if (weight[i] <= end+1) {
                end = end + weight[i];
            }
            else return end + 1;
        }
        return end + 1;
    }
    else {
        return 1;
    }
}