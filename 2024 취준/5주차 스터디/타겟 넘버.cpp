#include <bits/stdc++.h>

using namespace std;

vector<int> vc;
int answer = 0;

void DFS(int k, int n, vector<int> numbers, int target)
{
    if (k == n)
    {
        int temp = 0;

        for (auto u : vc)
        {
            temp += u;
        }

        if (temp == target)
        {
            answer++;
        }

        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (i)
        {
            vc.push_back(numbers[k]);
        }
        else
        {
            vc.push_back(-numbers[k]);
        }

        DFS(k + 1, n, numbers, target);

        vc.pop_back();
    }
}

int solution(vector<int> numbers, int target)
{

    DFS(0, numbers.size(), numbers, target);

    return answer;
}