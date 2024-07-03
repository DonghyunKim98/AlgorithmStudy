#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int T, R;
string s;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> R >> s;

        for (auto c : s)
        {
            for (int i = 0; i < R; i++)
                cout << c;
        }
        cout << endl;
    }

    return 0;
}

// 내 예전 풀이에서는 vector 에 차곡차곡 쌓는 식으로 풀었다.