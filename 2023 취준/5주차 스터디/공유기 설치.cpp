#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, C;
vector<ll> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end());

    int begin = 1, end = vc.at(vc.size() - 1) - vc.at(0);

    while (begin <= end)
    {
        int gap = (begin + end) / 2;
        // vc[0] 에는 설치하므로 cnt = 1;
        int cnt = 1;
        int std = vc[0];

        for (int i = 1; i < N; i++)
        {
            if (vc[i] - std >= gap)
            {
                cnt++;
                std = vc[i];
            }
        }

        // 공유기를 너무 많음 -> 간격이 너무 촘촘함 -> 간격을 늘려야함
        // 등호는 여기에 붙여야 함
        if (cnt >= C)
        {
            begin = gap + 1;
        }
        else
        {
            end = gap - 1;
        }
    }

    // 특정 조건을 만족하는 값에서 최대값이므로, end 가 곧 답임
    /*
        e.g [3,7] 이 모두 조건을 만족시킴 -> 답은 7임
            => 이를 위해서는 begin 값을 계속 늘려서 end 값인 7을 넘기는 순간 7이 정답이라고 볼 수 있음
    */
    cout << end;
}

/*
    Brutal force => 조합. O(n!)

    알고리즘 아이디어
    => 결국 집과 집사이의 '간격' 에 초점을 맞춰야 하는 것.
    => 이 간격을 parameter search로 찾아가면서 문제의 조건에 부합하는지를 확인.
    (적어도 이 간격을 유지하면서 원하는 공유기의 개수만큼 설치할 수 있는가?)

*/