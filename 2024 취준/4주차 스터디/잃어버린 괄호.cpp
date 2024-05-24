#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int tmp = 0, sum = 0;
bool flag = false;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string str;

    cin >> str;

    int len = str.length();

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (flag == true)
            {               //-가 이전에 들어왔음
                sum -= tmp; // 현재 부호는 상관없고 그냥 빼기
                tmp = 0;
            }
            else
            {
                sum += tmp; // 앞엔 다 +란 거니까 더하기
                tmp = 0;
                if (str[i] == '-')
                { //-가 처음 들어온상황
                    flag = true;
                }
            }
        }
        else
        {
            tmp *= 10;           // 기존거 왼쪽으로 보내고 (자리수 하나 올려주고)
            tmp += str[i] - '0'; // char->숫자로 변경
        }
    }
    cout << sum << endl;
}

/*
    '탐욕스럽게' = '-와 -사이는 전부 괄호를 쳐서' 로 해석하는 문제.
    그래야 -되는 값이 최대가 되서 전체 수식의 값이 최소가 된다.
    EX
    1. 55-50+40 => 55-(50+40) = -35
    2. -40+20-30 => -(40+20)-30 -= -90
*/