#include <bits/stdc++.h>

using namespace std;

int N, K;

bool comp(pair<int, vector<int>> a, pair<int, vector<int>> b)
{
    if (a.second[0] != b.second[0]) // Compare Gold medals
        return a.second[0] > b.second[0];
    if (a.second[1] != b.second[1]) // Compare Silver medals
        return a.second[1] > b.second[1];
    return a.second[2] > b.second[2]; // Compare Bronze medals
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> K;

    vector<pair<int, vector<int>>> vc;
    for (int i = 0; i < N; i++)
    {
        int number, gold, silver, bronze;
        cin >> number >> gold >> silver >> bronze;
        vc.push_back({number, {gold, silver, bronze}});
    }

    sort(vc.begin(), vc.end(), comp);

    int rank = 1;
    for (int i = 0; i < vc.size(); i++)
    {
        if (i > 0 && vc[i].second == vc[i - 1].second)
        {
            // If the medals are the same as the previous, assign the same rank
            // Do nothing, keep the same rank
        }
        else
        {
            rank = i + 1;
        }

        if (vc[i].first == K)
        {
            cout << rank;
            return 0;
        }
    }
}
