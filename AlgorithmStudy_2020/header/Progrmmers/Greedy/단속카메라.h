#include <bits/stdc++.h>
using namespace std;
const int MAX = 30000 + 1;
bool comp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] > b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int> > routes)
{
    int answer = 0;
    // 빨리 끝나는 순으로 정렬
    sort(routes.begin(), routes.end(), comp);
    while (!routes.empty())
    {
        // 제일 먼저 끝나는 친구.
        int number = routes[0][1];
        int idx = 0;
        while (idx != routes.size())
        {
            if (routes[idx][0] <= number && number <= routes[idx][1])
            {
                routes.erase(routes.begin() + idx);
            }
            else
            {
                idx++;
            }
        }
        answer++;
    }
    return answer;
}

/*
    알고리즘 포인트
    => 책에서 배웠던 이벤트 스케쥴링의 변형. 결국 같은 방식으로 푸는 것
    이 문제를 풀면서 느낀 점 : 기존의 문제와 어떻게 유사한지를 파악하는 것이 핵심이다.
*/