#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp != 0)
        {
            pq.push(temp);
        }
        else
        {
            if (pq.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
}