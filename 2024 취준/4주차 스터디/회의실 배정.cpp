#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> vc;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vc.push_back({temp1, temp2});
    }

    sort(vc.begin(), vc.end(), comp);

    // cout << vc[0].first << ' ' << vc[0].second << endl;

    int ans = 1, last_schedule_end_time = vc[0].second;
    for (int i = 1; i < N; i++)
    {
        if (vc[i].first < last_schedule_end_time) // 시작 시간이 직전 종료시간보다 빠름 -> 못 들어옴
        {
            continue;
        }
        ans++;
        last_schedule_end_time = vc[i].second;
    }

    cout << ans << endl;
}

/*
    1931번 문제 -> 이거 초록책에 있는 내용인데.. (이벤트 스케쥴랑, 55페이지에 있음)
    '탐욕스럽게' = 끝나는 시간이 빠른 순서대로 일단 집어넣기
    (why?) [0,4] 와 [1,3] 이 있다고 하자. 끝나는 시간이 3인게 더 좋다. 그래야 [3,end] 사이에 더 회의를 집어넣을 수 있으니깐

    85% 에서 틀린 이유 -> comp 함수에서 처음에는 끝나는 시간만 정렬했기 때문, 시작 시간도 오름차순으로 정렬을 해야함 (그래야 끝나는 시간이 같을때, 시작 시간이 빠른걸 집어넣어야 됨)

    [반례]
    (Q)
    4
    3 3
    2 3
    1 3
    2 2

    (A)
    3
*/