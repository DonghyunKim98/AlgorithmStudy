#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    stack<char> left_stack;
    stack<char> right_stack;
    for (auto u : s)
    {
        left_stack.push(u);
    }

    int N;
    cin >> N;

    string flush;
    getline(cin, flush); // 버퍼 비우기

    while (N--)
    {
        string temp;
        getline(cin, temp);

        if (temp[0] == 'L')
        {
            if (!left_stack.empty())
            {
                char leftChar = left_stack.top();
                left_stack.pop();
                right_stack.push(leftChar);
            }
        }
        else if (temp[0] == 'D')
        {
            if (!right_stack.empty())
            {
                char rightChar = right_stack.top();
                right_stack.pop();
                left_stack.push(rightChar);
            }
        }
        else if (temp[0] == 'B')
        {
            if (!left_stack.empty())
                left_stack.pop();
        }
        // p $ 인 경우
        else
        {
            left_stack.push(temp[2]);
        }
    }

    string s2;
    while (!left_stack.empty())
    {
        s2 += left_stack.top();
        left_stack.pop();
    }

    for (int i = s2.length() - 1; i >= 0; i--)
    {
        cout << s2[i];
    }

    while (!right_stack.empty())
    {
        cout << right_stack.top();
        right_stack.pop();
    }
}