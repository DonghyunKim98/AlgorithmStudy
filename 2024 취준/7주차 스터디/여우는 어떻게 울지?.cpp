#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> T;
    cin.clear();

    string flush;
    getline(cin, flush); // 버퍼 비우기

    while (T--)
    {
        string s, temp;
        getline(cin, s);
        map<string, bool> visited;

        while (1)
        {
            getline(cin, temp);
            string a;
            bool q = false;
            // 문자열 끝부터 시작 -> 끝에서 울음
            for (int j = temp.length() - 1; j >= 0; j--)
            {
                if (temp[j] == ' ')
                {
                    // 그래서 뒤짚어야 함
                    reverse(a.begin(), a.end());
                    if (a == "say?")
                    {
                        q = true;
                        break;
                    }
                    visited[a] = true;
                    break;
                }
                else
                {
                    a += temp[j];
                }
            }

            if (q)
            {
                break;
            }
        }
        temp.clear();

        vector<string> res;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == ' ')
            {
                if (!visited.count(temp))
                {
                    res.push_back(temp);
                }
                temp.clear();
            }
            else
            {
                temp += s[j];
            }
        }

        if (!visited.count(temp))
        {
            res.push_back(temp);
        }
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[j] << " ";
        }
        cout << endl;
    }
}