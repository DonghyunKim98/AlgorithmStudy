#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M;
vector<ll> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        vc.push_back(temp);
    }

    sort(vc.begin(), vc.end());

    ll begin = 1, end = vc[0] * M;
    /*
        time 초에 M명이 통과할 수 있는가? 를 보면 됨
        How?) cnt += time / vc[i] (각 심사대에서 통과 가능한 사람 숫자) -> 가장 짧은 시간이 걸리는 심사대는 끊임없이 돌아감

        begin = 1초
        end = 가장 짧은 시간이 걸리는 심사대 시간 X 사람 수

        N명 보다 더 통과함 -> 시간이 넘침 -> end를 줄여야 함
        N명 보다 덜 통과함 -> 시간이 부족함 -> begin 을 늘려야 함

        구간 [4, 8] 에 전부 N명 통과 가능 -> 4가 정담 (end 를 줄여나가고, begin 이 정답)
    */

    while (begin <= end)
    {
        ll time = (begin + end) / 2;
        ll cnt = 0;

        for (int i = 0; i < vc.size(); i++)
        {
            ll current_possible_cnt = time / vc.at(i);
            if (current_possible_cnt == 0)
            {
                break;
            }
            cnt += current_possible_cnt;
        }

        if (cnt >= M)
        {
            end = time - 1;
        }
        else
        {
            begin = time + 1;
        }
    }

    cout << begin;
}