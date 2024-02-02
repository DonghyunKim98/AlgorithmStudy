#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

void solution()
{
    int p, m;
    cin >> p >> m;
    vector<pair<string, int> > pq[310];
    // 우선 순위 첫번째 string 값만을 비교하면 되니 greater로 만들었습니다.

    for (int i = 0; i < p; i++)
    { // p만큼 돌리기.
        int temp;
        string temp2;
        cin >> temp >> temp2; // 값 입력.

        int flag = 0;

        for (int j = 0; j <= i; j++)
        {
            if (pq[j].size() < m && pq[j].size() > 0)
            {
                if (abs(pq[j][0].second - temp) <= 10)
                {
                    flag = 1;
                    pq[j].push_back(make_pair(temp2, temp));
                    break;
                }
            }
        }
        if (flag == 0)
        {
            pq[i].push_back(make_pair(temp2, temp));
        }
    }

    for (int i = 0; i < 300; i++)
    {
        if (pq[i].size() == 0)
        {
            continue;
        }
        else if (pq[i].size() >= m)
        {
            cout << "Started!" << endl;
        }
        else if (pq[i].size() > 0 && pq[i].size() < m)
        {
            cout << "Waiting!" << endl;
        }

        sort(pq[i].begin(), pq[i].end());

        for (int j = 0; j < pq[i].size(); j++)
        {
            cout << pq[i][j].second << " " << pq[i][j].first << endl;
        }
    }
}