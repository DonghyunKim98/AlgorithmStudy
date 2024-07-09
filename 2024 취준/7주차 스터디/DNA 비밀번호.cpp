#include <bits/stdc++.h>

using namespace std;

int S, P;
int A_num, C_num, G_num, T_num;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> S >> P;

    string s;
    cin >> s;

    cin >> A_num >> C_num >> G_num >> T_num;
    int cur_A_num = 0, cur_C_num = 0, cur_G_num = 0, cur_T_num = 0;

    int ans = 0;

    for (int i = 0; i < P; i++)
    {
        char u = s[i];

        switch (u)
        {
        case 'A':
            cur_A_num++;
            break;
        case 'C':
            cur_C_num++;
            break;
        case 'G':
            cur_G_num++;
            break;
        case 'T':
            cur_T_num++;
            break;
        default:
            break;
        }
    }

    if (cur_A_num >= A_num && cur_C_num >= C_num && cur_G_num >= G_num && cur_T_num >= T_num)
    {
        ans++;
    }

    for (int i = 1; i <= S - P; i++)
    {
        char plus = s[i + P - 1];
        char minus = s[i - 1];

        switch (plus)
        {
        case 'A':
            cur_A_num++;
            break;
        case 'C':
            cur_C_num++;
            break;
        case 'G':
            cur_G_num++;
            break;
        case 'T':
            cur_T_num++;
            break;
        default:
            break;
        }

        switch (minus)
        {
        case 'A':
            cur_A_num--;
            break;
        case 'C':
            cur_C_num--;
            break;
        case 'G':
            cur_G_num--;
            break;
        case 'T':
            cur_T_num--;
            break;
        default:
            break;
        }

        if (cur_A_num >= A_num && cur_C_num >= C_num && cur_G_num >= G_num && cur_T_num >= T_num)
        {
            ans++;
        }
    }
    cout << ans;
}

// Sliding Window 기법을 잘 기억해두자