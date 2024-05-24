#include <bits/stdc++.h>

#define MAX 15

using namespace std;

int N;
int cnt = 0;
int col[15];
int diag1[30];
int diag2[30];

void DFS(int y)
{
    if (y == N)
    {
        cnt++;
        return;
    }
    for (int x = 0; x < N; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + N - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + N - 1] = 1;
        DFS(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + N - 1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    DFS(0);

    cout << cnt;

    return 0;
}

/*
    N-Queen
    가장 대표적인 백트래킹 문제
    1. visited 에 매몰될 필요가 없다. 이 문제는 탐색 알고리즘이 아니라 백트래킹 알고리즘이기 때문이다.
        - 물론 DFS 자체가 백트래킹 형식이기 때문에 함수이름을 DFS 로 가져간다.
    2. 기본 아이디어는 퀸을 1개의 행마다 배치를 해보면서 되는지 안되는지 해보는 것
        - col 배열은 몇번째 행에 퀸이 놓여져 있음을 의미
        - diag1 배열은 좌상<->우하에 퀸이 놓여져 있음을 의미
        - diag2 배열은 좌하<->우상에 퀸이 놓여져 있음을 의미
    3. 행렬로 생각할것 (좌상이 [0,0] 임)
    4. 다른풀이 -> https://cryptosalamander.tistory.com/58#google_vignette
*/