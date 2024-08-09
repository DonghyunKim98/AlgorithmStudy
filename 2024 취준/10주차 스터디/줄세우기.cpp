#include <bits/stdc++.h>

using namespace std;

int students[20];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int P, num, result = 0;
    cin >> P;

    for (int tc = 0; tc < P; tc++)
    {
        cin >> num;
        result = 0;
        for (int i = 0; i < 20; i++)
            cin >> students[i];
        for (int i = 0; i < 20; i++)
        {
            for (int j = i; j < 20; j++)
            {
                if (students[i] > students[j])
                    result += 1;
            }
        }
        cout << num << ' ' << result << "\n";
    }

    return 0;
}