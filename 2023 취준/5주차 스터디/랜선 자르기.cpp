#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int K, N;
vector<int> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;
        vc.push_back(temp);
    }

    sort(vc.begin(), vc.end());

    ll begin = 1, end = vc[vc.size() - 1];

    // 1부터 max 까지 범위 내에서 잘라야함
    // min 보다 작다고 생각하면 안됨 -> min 보다 크게 해서 몇몇 랜선 자체를 안 쓸수도 있음
    while (begin <= end)
    {
        ll mid = (begin + end) / 2;
        ll cnt = 0;
        for (int i = 0; i < vc.size(); i++)
        {
            cnt += vc[i] / mid;
        }

        if (cnt >= N)
            begin = mid + 1;
        else
            end = mid - 1;
    }

    cout << end;
}

/*
    N 개를 만들건데 그 중 최대 길이...?

    문제 핵심 : [1,max(K)] 중에서 문제의 조건(구현)을 마쳤을때 최대가 되는 값찾기 -> 이진탐색으로 줄여나가야함?
    너무 크게 자름 -> 잘라낸 토막이 적음 -> 기준 값에 못미친다 -> 구간의 최대값을 줄임 : 이해됨
    너무 작게 자름 -> 잘라낸 토막이 많음 -> 기준 값보다 크다 -> 구간의 최소 값을 줄임 : 이헤됨

    Parametric Search : 내가 원하는 실수의 정답의 범위에서 이진탐색을 진행
    - 내가 원하는 조건을 만족하는 가장 알맞는 값을 찾는 것
*/