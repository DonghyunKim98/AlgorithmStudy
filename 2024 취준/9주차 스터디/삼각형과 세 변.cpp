#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (!a && !b && !c)
            return 0;

        // invalid 판단
        vector<int> vc;
        vc.push_back(a);
        vc.push_back(b);
        vc.push_back(c);

        sort(vc.begin(), vc.end());

        if (vc[0] + vc[1] <= vc[2])
        {
            cout << "Invalid" << endl;
            continue;
        }

        // 정삼각형 및 이등변삼각형
        if (vc[0] == vc[1] || vc[1] == vc[2] || vc[2] == vc[0])
        {
            if (vc[0] == vc[1] && vc[1] == vc[2])
            {
                cout << "Equilateral" << endl;
                continue;
            }

            cout << "Isosceles" << endl;
            continue;
        }

        cout << "Scalene" << endl;
    }
}