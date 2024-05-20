#include <bits/stdc++.h>
#define MAX 1000000
#define endl '\n'

using namespace std;

typedef long long ll;

int N, M;
ll arr[MAX];

map<ll, bool> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        mp.insert({arr[i], true});
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        ll temp;
        cin >> temp;

        if (mp.find(temp) != mp.end())
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}