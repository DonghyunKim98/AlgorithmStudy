#include <bits/stdc++.h>

using namespace std;
int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    unordered_map<string, int> mp;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        mp[s] = i;
    }

    vector<string> vc;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        vc.push_back(s);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (mp[vc[i]] > mp[vc[j]])
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}

// 참고 https://100100e.tistory.com/297
// 같은 순서로 들어오더라도 추월하는 경우가 있음
// 내 뒷 차량에 나보다 먼저 들어온 차량이 있으면 추월한 것임