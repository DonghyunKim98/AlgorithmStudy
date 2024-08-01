#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int M, x, S = 0;
    cin >> M;

    string str;

    while (M--)
    {

        cin >> str;

        if (str == "add")
        {
            cin >> x;
            S |= (1 << x);
        }

        else if (str == "remove")
        {
            cin >> x;
            S &= ~(1 << x);
        }
        else if (str == "check")
        {
            cin >> x;
            if (S & (1 << x))
            { // 있으면
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (str == "toggle")
        {
            cin >> x;
            S ^= (1 << x);
        }
        else if (str == "all")
        {
            S = (1 << 21) - 1;
        }
        else if (str == "empty")
        {
            S = 0;
        }
    }

    return 0;
}