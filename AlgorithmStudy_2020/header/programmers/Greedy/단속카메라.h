#include <bits/stdc++.h>
using namespace std;
const int MAX = 30000 + 1;
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int* positiveArr = new int[MAX];
    int* negativeArr = new int[MAX];
    int zero = 0;
    fill_n(positiveArr, MAX, 0);
    fill_n(negativeArr, MAX, 0);
    for (int i = 0; i < routes.size(); i++) {
        int start = routes[i][0];
        int end = routes[i][1];
        //[+,+]
        if (start > 0 && end > 0) {
            for (int j = start; j <= end; j++)
                positiveArr[j]++;
        }
        //[-,+]
        else if (start < 0 && end > 0) {
            for (int j = 1; j <= end; j++)
                positiveArr[j]++;
            for (int j = 1; j <= -start; j++)
                negativeArr[j] ++;
            zero++;
        }
        //[-,-]
        else if (start < 0 && end < 0) {
            for (int j = -end; j <= -start; j++)
                negativeArr[j]++;
        }
        //[0,+]
        else if (start == 0 && end > 0) {
            zero++;
            for (int j = 1; j <= end; j++)
                positiveArr[j]++;
        }
        //[-,0]
        else if (start < 0 && end == 0) {
            zero++;
            for (int j = 1; j <= -start; j++)
                negativeArr[j] ++;
        }
    }

    return answer;
}