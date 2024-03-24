// 스도쿠
#include <bits/stdc++.h>
#define MAX 9
#define endl '\n'

using namespace std;

int board[MAX][MAX];

bool check(int x, int y, int k)
{
    // 1번 -> 가로 상황 체크
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == k)
        {
            return false;
        }
    }
    // 2번 -> 세로 상황 체크
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == k)
        {
            return false;
        }
    }
    // 3번 -> 정사각형 체크
    int xx = (x / 3) * 3, yy = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[xx + i][yy + j] == k)
            {

                return false;
            }
        }
    }
    return true;
}

void DFS(int n)
{
    if (n == 81)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }

    int x = n / 9, y = n % 9;

    // board[x][y] 가 0이 아님 (이미 채워져 있음) -> 다음으로
    if (board[x][y])
    {
        return DFS(n + 1);
    }
    for (int k = 1; k <= 9; k++)
    {
        int is_K_Available = check(x, y, k);
        if (is_K_Available)
        {
            board[x][y] = k;
            DFS(n + 1);
            board[x][y] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> board[i][j];
        }
    }

    DFS(0);

    return 0;
}

/*
    백트래킹 문제
    해설 1번 : https://velog.io/@junttang/BOJ-2580-%EC%8A%A4%EB%8F%84%EC%BF%A0-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5
    해설 2번 : https://jaimemin.tistory.com/664 (예전 풀이)

    Tip 1번 : x,y 좌표를 다 넘길 필요 없음 -> n 만 넘겨도 x,y 계산 가능
    Tip 2번 : x,y 라고 index 에 명시하기
    Tip 3번 : 내가 푼 코드처럼해도 일단 시간 초과는 나오지 않지만, 탐색 과정에서 미리 파악하여 조금이라도 시간을 더 줄일 수 있는 방법은 존재함
*/