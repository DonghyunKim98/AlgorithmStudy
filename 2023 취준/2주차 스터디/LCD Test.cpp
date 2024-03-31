#include <iostream>
using namespace std;

int s = 0;
string n = "";
// 레전드 띵킹 헉..
int temp[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

void monitor(char c, int idx)
{ // 찍히는 숫자, 0~6사이 위치
    int x = c - '0';
    if (idx % 3 == 0)
    {
        cout << " ";
        if (temp[x][idx] == 1)
        {
            for (int i = 0; i < s; i++)
                cout << "-";
        }
        else
        {
            for (int i = 0; i < s; i++)
                cout << " ";
        }
        cout << "  ";
    }
    else
    {
        if (temp[x][idx] == 1)
        {
            cout << "|";
        }
        else
            cout << " ";
        if (idx % 3 == 1)
        {
            for (int i = 0; i < s; i++)
                cout << " ";
        }
        else
            cout << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> n;
    for (int j = 0; j < n.size(); j++)
    {                     // 0
        monitor(n[j], 0); // 찍히는 숫자, 0~6사이 위치
    }
    cout << "\n";
    for (int a = 0; a < s; a++)
    {
        for (int j = 0; j < n.size(); j++)
        { // 1~2
            for (int i = 1; i < 3; i++)
            {
                monitor(n[j], i); // 찍히는 숫자, 0~6사이 위치
            }
        }
        cout << "\n";
    }
    for (int j = 0; j < n.size(); j++)
    {                     // 3
        monitor(n[j], 3); // 찍히는 숫자, 0~6사이 위치
    }
    cout << "\n";
    for (int a = 0; a < s; a++)
    {
        for (int j = 0; j < n.size(); j++)
        { // 4~5
            for (int i = 4; i < 6; i++)
            {
                monitor(n[j], i); // 찍히는 숫자, 0~6사이 위치
            }
        }
        cout << "\n";
    }
    for (int j = 0; j < n.size(); j++)
    {                     // 6
        monitor(n[j], 6); // 찍히는 숫자, 0~6사이 위치
    }
    cout << "\n";
    return 0;
}