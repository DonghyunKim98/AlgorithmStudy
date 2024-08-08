#include <bits/stdc++.h>
#define MAX 201
using namespace std;

int N, K;
int belt[MAX * 2];
bool has_robot[MAX * 2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> belt[i];
    }

    int start = 0;   // 벨트의 시작 지점
    int end = N - 1; // 벨트의 끝 지점
    int ans = 0;

    while (true)
    {
        ans++;

        // 1번: 벨트 회전 -> -1 을 하는게 가장 중요함
        start = (start - 1 + 2 * N) % (2 * N);
        end = (end - 1 + 2 * N) % (2 * N);

        // 로봇 이동 업데이트
        if (has_robot[end])
        {
            has_robot[end] = false; // 로봇이 내려감
        }

        // 2번: 로봇 이동
        for (int i = N - 2; i >= 0; i--)
        {
            int cur = (start + i) % (2 * N);
            int next = (cur + 1) % (2 * N);
            if (has_robot[cur] && !has_robot[next] && belt[next] > 0)
            {
                has_robot[cur] = false;
                has_robot[next] = true;
                belt[next]--;
            }
        }

        // 로봇 이동 업데이트
        if (has_robot[end])
        {
            has_robot[end] = false; // 로봇이 내려감
        }

        // 3번: 로봇 올리기
        if (belt[start] > 0 && !has_robot[start])
        {
            has_robot[start] = true;
            belt[start]--;
        }

        // 4번: 내구도 체크
        int cnt = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (belt[i] == 0)
                cnt++;
        }

        if (cnt >= K)
        {
            cout << ans << '\n';
            break;
        }
    }

    return 0;
}

/*
    index 만으로 관리하는 것
*/