#include <bits/stdc++.h>
#define MAX 101
#define endl '\n'

using namespace std;

int N, M;
int switches[MAX];

void man_switch(int idx)
{
    for (int i = idx; i < MAX; i += idx)
    {
        switches[i] = !switches[i];
    }
}

void woman_switch(int idx)
{
    //  자기 자신
    switches[idx] = !switches[idx];

    for (int i = 1; i < MAX; i++)
    {
        int left_idx = idx - i, right_idx = idx + i;
        if (left_idx < 1 || right_idx > N)
        {
            return;
        }

        // 하.. .서로 맞지 않으면 탈출해야했는데...
        if (switches[left_idx] != switches[right_idx])
        {
            return;
        }

        switches[left_idx] = !switches[left_idx];
        switches[right_idx] = !switches[right_idx];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> switches[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int sex, idx;
        cin >> sex >> idx;
        sex == 1 ? man_switch(idx) : woman_switch(idx);
    }

    // 출력
    for (int i = 1; i <= N; i++)
    {
        cout << switches[i] << ' ';
        if (i % 20 == 0) // 20개의 숫자를 출력했다면 줄바꾸기
            cout << endl;
    }
    return 0;
}