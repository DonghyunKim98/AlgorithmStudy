#include <bits/stdc++.h>
#define MAX 301
#define endl '\n'
using namespace std;
typedef pair<int, string> pis;
int p, m;

bool pis_sort(pis a, pis b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> p >> m;

    vector<pis> vc;

    for (int i = 0; i < p; i++)
    {
        int level;
        string id;

        cin >> level >> id;

        vc.push_back({level, id});
    }
    vector<vector<pis>> room;

    for (int i = 0; i < p; i++)
    {
        bool flag = false;
        for (auto &u : room) // 참조로 변경
        {
            if (abs(u[0].first - vc[i].first) <= 10 && u.size() < m)
            {
                u.push_back(vc[i]);
                flag = true;
                break;
            }
        }
        // 방을 찾지 못했음
        if (!flag)
        {
            vector<pis> temp = {vc[i]};
            room.push_back(temp);
        }
    }

    // 출력
    for (auto &u : room)
    {
        if (u.size() == m)
            cout << "Started!" << endl;
        else
            cout << "Waiting!" << endl;

        sort(u.begin(), u.end(), pis_sort);

        for (auto r : u)
        {
            cout << r.first << ' ' << r.second << endl;
        }
    }
}
