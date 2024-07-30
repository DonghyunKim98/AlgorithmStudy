#include <bits/stdc++.h>
#define MAX
using namespace std;

int N;
vector<int> vc;
long long budget;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int max_request = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        vc.push_back(temp);
        max_request = max(temp, max_request);
    }

    cin >> budget;

    // 최댓값은 무조건 max_request임
    int start = 0, end = max_request;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int total = 0;
        for (auto u : vc)
        {
            total += min(mid, u);
        }

        if (total > budget)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << end;
}