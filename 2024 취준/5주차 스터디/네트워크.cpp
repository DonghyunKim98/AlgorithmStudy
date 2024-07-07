#include <bits/stdc++.h>
#define MAX 201
using namespace std;

bool visited[MAX];
int answer = 0;

void DFS(vector<vector<int>> &computers, int k, int n)
{
    visited[k] = true; // 현재 노드 방문 표시
    for (int i = 0; i < n; i++)
    { // 모든 노드를 검사
        if (!visited[i] && computers[k][i] == 1)
        {
            DFS(computers, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    memset(visited, 0, sizeof(visited)); // visited 배열 초기화

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(computers, i, n);
            answer++;
        }
    }

    return answer;
}