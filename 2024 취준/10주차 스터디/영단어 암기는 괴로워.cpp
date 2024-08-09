#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<string, int> psi;

int N, M;

bool comp(psi a, psi b)
{
    return a.second == b.second
               ? a.first.size() == b.first.size()
                     ? a.first < b.first
                     : a.first.size() > b.first.size()
               : a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;

    map<string, int> mp;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        if (temp.size() < M)
            continue;
        mp[temp]++;
    }

    vector<pair<string, int>> vc(mp.begin(), mp.end());
    sort(vc.begin(), vc.end(), comp);

    for (auto u : vc)
    {
        cout << u.first << endl;
    }
}