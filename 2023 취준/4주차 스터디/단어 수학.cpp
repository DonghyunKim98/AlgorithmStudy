#include <bits/stdc++.h>

using namespace std;

int n;
int a[26];

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int v = 1;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            a[s[j] - 'A'] += v;
            v *= 10;
        }
    }

    sort(a, a + 26, cmp);

    int num = 9, ret = 0;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] == 0)
            break;
        ret += a[i] * num--;
    }
    cout << ret;
    return 0;
}

/*
    1339번 문제
    '탐욕스럽게' = '최대한 높은 자리 숫자에 있는, 그러면서 더 자주 등장하는 알파벳에 높은 숫자를 부여'
    How?) 자릿수의 합을 구하여라! -> 이를 이용하면 한 번에 sort 와 계산을 할 수 있다.

    참고 : https://velog.io/@rhkswls98/%EB%B0%B1%EC%A4%80-1339-C-%EB%8B%A8%EC%96%B4-%EC%88%98%ED%95%99
*/