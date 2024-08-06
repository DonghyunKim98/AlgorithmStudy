#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
typedef long long ll;

int T, N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> vc;

        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            vc.push_back(temp);
        }

        ll result = 0;
        int max_value = -1;

        for (int i = N - 1; i >= 0; i--)
        {
            max_value = max(max_value, vc[i]);
            result += max_value - vc[i];
        }
        cout << result << "\n";
    }
}