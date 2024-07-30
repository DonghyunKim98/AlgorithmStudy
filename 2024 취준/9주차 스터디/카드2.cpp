#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N;
    queue<int> q;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while (true)
    {
        int currentTop = q.front();
        q.pop();
        if (q.empty())
        {
            cout << currentTop;
            return 0;
        }

        int secondCurrentTop = q.front();
        q.pop();
        q.push(secondCurrentTop);
    }
}