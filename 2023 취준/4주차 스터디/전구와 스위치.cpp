#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

int N, ans = -1;
string source_str, destination_str;

char change(char ch)
{
    if (ch == '0')
        return '1';
    else
        return '0';
}

void solution(string &str, int cnt, int x)
{
    if (x == N)
    {
        if (str[x - 1] == destination_str[x - 1])
        {
            if (ans == -1)
                ans = cnt;
            else
                ans = min(ans, cnt);
        }
        return;
    }

    if (str[x - 1] == destination_str[x - 1])
        solution(str, cnt, x + 1);
    else
    { // 뒤집기
        str[x - 1] = change(str[x - 1]);
        str[x] = change(str[x]);
        if (x + 1 < N)
            str[x + 1] = change(str[x + 1]);
        solution(str, cnt + 1, x + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    cin >> source_str;
    cin >> destination_str;

    string tmp = source_str;
    solution(source_str, 0, 1);

    if (ans == -1)
    {
        source_str = tmp;
        source_str[0] = change(source_str[0]);
        source_str[1] = change(source_str[1]);
        solution(source_str, 1, 1);
    }
    cout << ans << '\n';
    return 0;
}

/*
    2138번 문제
    핵심 아이디어 : i위치에서 0부터 i-1까지는 정답과 같아야 다음으로 넘어갈수 있다.
        (why?) : i+1 위치에서는 i-1 을 바꿀 수 없기 때문
    '탐욕스럽게' = '각 전구 위치에서 before 전구까지 답이 맞는지 한번만 체크하면서'

    의문점 -> 이게 진짜 최소일까?

*/