#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N;
    vector<pii> vc;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vc.push_back({temp1, temp2});
    }

    for (int i = 0; i < N; i++)
    {
        // 처음에 1등으로 출발
        int ans = 1;
        pii current = vc[i];

        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            pii compare = vc[j];
            if (current.first < compare.first && current.second < compare.second)
            {
                ans++;
            }
        }
        cout << ans << ' ';
    }
}