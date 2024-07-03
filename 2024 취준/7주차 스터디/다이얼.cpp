#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c <= 'O')
        {
            ans += ((c - 'A') / 3) + 3;
        }
        else if (c >= 'P' && c <= 'S')
        {
            ans += 8;
        }
        else if (c >= 'T' && c <= 'V')
        {
            ans += 9;
        }
        else
            ans += 10;
    }

    cout << ans;
}