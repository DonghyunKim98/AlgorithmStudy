#include <bits/stdc++.h>
// 14891번 문제
using namespace std;
deque<bool> sawtooth[5];
bool visited[5];
int K;

void Rotate(int idx, int dir)
{
    if (dir == 1)
    {
        sawtooth[idx].push_front(sawtooth[idx].back());
        sawtooth[idx].pop_back();
    }
    else
    {
        sawtooth[idx].push_back(sawtooth[idx].front());
        sawtooth[idx].pop_front();
    }
}

bool is_rotate(int left, int right)
{
    if (sawtooth[left][2] == sawtooth[right][6])
        return false;
    else
        return true;
}
void check(int idx, int dir)
{
    visited[idx] = true;
    int prev = idx - 1, nxt = idx + 1;
    if (1 <= prev && is_rotate(prev, idx) && !visited[prev])
    {
        check(prev, -dir);
    }
    if (nxt <= 4 && is_rotate(idx, nxt) && !visited[nxt])
    {
        check(nxt, -dir);
    }

    // 회전
    Rotate(idx, dir);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= 4; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 8; j++)
        {
            sawtooth[i].push_back(bool(temp[j] - '0'));
        }
    }

    cin >> K;

    while (K > 0)
    {
        int number, dir;
        cin >> number >> dir;
        check(number, dir);
        memset(visited, false, sizeof(visited));
        K--;
    }

    int answer = 0;

    for (int i = 1; i <= 4; i++)
        answer += (sawtooth[i][0]) ? pow(2, i - 1) : 0;

    std::cout << answer;
}