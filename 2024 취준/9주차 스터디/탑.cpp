#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N;
    stack<pii> st;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        while (!st.empty())
        {
            pii top = st.top();
            if (top.first >= temp)
            {
                cout << top.second << ' ';
                st.push(top);
                st.push({temp, i + 1});
                break;
            }
            else
            {
                st.pop();
            }
        }

        if (st.empty())
        {
            cout << 0 << ' ';
            st.push({temp, i + 1});
        }
    }
}