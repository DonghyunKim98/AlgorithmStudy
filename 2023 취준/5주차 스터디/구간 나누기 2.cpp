#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> vc;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        vc.push_back(temp);
    }

    int begin = 0, end = 10000;

    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        // 첫 구간이 있으므로
        int cnt = 1;
        int min_value = vc[0], max_value = vc[0];

        for (int i = 1; i < vc.size(); i++)
        {
            min_value = min(min_value, vc[i]);
            max_value = max(max_value, vc[i]);

            int gap = max_value - min_value;

            // 설정한 구간의 최댓값을 넘침 -> 구간 추가
            if (gap > mid)
            {
                cnt++;
                min_value = vc[i];
                max_value = vc[i];
            }
        }

        // 구간이 더 필요함 -> 아래의 3번이 작음 , 등호는 붙이지 않음 (M개 이하가 정답이므로)
        if (cnt > M)
        {
            begin = mid + 1;
        }
        // 구간이 덜 필요함 -> 아래의 3번이 큼
        else
        {
            end = mid - 1;
        }
    }

    cout << begin;
}

/*
    용어 정리
    1. 구간의 점수 : (구간의 최대값) - (구간의 최소값)
    2. 구간의 점수 최댓값 : 1번의 최댓값
    3. 구해야하는 것 : 2번의 최솟값

    => 2번을 탐색해야 함!
    (How?) 구간의 점수 최댓값을 6으로 하고 싶어!

    많이 쪼개면 쪼갤수록 3번이 작아짐 (최대 N 만큼 쪼개면 최댓값은 0임)


    구간 [10,20] 이 모두 M 개 이하의 구간으로 나눌 수 있음 -> 10이 정답
*/