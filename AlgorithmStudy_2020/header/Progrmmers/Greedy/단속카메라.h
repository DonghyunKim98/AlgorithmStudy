#include <bits/stdc++.h>
using namespace std;
const int MAX = 30000 + 1;
bool comp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] > b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int> > routes)
{
    int answer = 0;
    // ���� ������ ������ ����
    sort(routes.begin(), routes.end(), comp);
    while (!routes.empty())
    {
        // ���� ���� ������ ģ��.
        int number = routes[0][1];
        int idx = 0;
        while (idx != routes.size())
        {
            if (routes[idx][0] <= number && number <= routes[idx][1])
            {
                routes.erase(routes.begin() + idx);
            }
            else
            {
                idx++;
            }
        }
        answer++;
    }
    return answer;
}

/*
    �˰��� ����Ʈ
    => å���� ����� �̺�Ʈ �����층�� ����. �ᱹ ���� ������� Ǫ�� ��
    �� ������ Ǯ�鼭 ���� �� : ������ ������ ��� ���������� �ľ��ϴ� ���� �ٽ��̴�.
*/