#include <bits/stdc++.h>
using namespace std;

void go(string s, string t)
{
    if (s == t)
    {
        cout << 1;
        exit(0);
    }
    if (s.length() > t.length())
    {
        return;
    }

    if (t[t.size() - 1] == 'A')
    {
        string temp = t;
        temp.erase(temp.size() - 1);
        go(s, temp);
    }

    if (t[0] == 'B')
    {
        string temp = t;
        reverse(temp.begin(), temp.end());
        temp.erase(temp.size() - 1);
        go(s, temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S, T;
    cin >> S >> T;

    go(S, T);
    cout << 0;

    return 0;
}