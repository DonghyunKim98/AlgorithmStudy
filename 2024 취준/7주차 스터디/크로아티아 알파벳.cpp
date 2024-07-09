#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int ans = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        ans++;
        // s= 와 z= 검사
        if (s[i] == 's' || s[i] == 'z')
        {
            if (i + 1 < s.length() && s[i + 1] == '=')
            {
                i++;
            }
        } // lj 와 nj 검사
        else if (s[i] == 'l' || s[i] == 'n')
        {
            if (i + 1 < s.length() && s[i + 1] == 'j')
            {
                i++;
            }
        } // dz= 와 d- 검사
        else if (s[i] == 'd')
        {
            if (i + 1 < s.length() && s[i + 1] == '-')
            {
                i++;
            }
            else if (i + 1 < s.length() && i + 2 < s.length() && s[i + 1] == 'z' && s[i + 2] == '=')
            {
                i += 2;
            }
        } // c= 와 c-검사
        else if (s[i] == 'c')
        {
            if (i + 1 < s.length() && (s[i + 1] == '=' || s[i + 1] == '-'))
            {
                i++;
            }
        }
    }

    cout << ans;
}

// 변수명을 current 와 next 를 이용하면 덜 헷갈릴듯?
