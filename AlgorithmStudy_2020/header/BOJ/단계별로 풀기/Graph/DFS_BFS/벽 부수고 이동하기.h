#include <bits/stdc++.h>
//2206번 문제 -> 풀었음(O)
//https://yabmoons.tistory.com/73 참고
//https://jaimemin.tistory.com/650 참고
using namespace std;
const int MAX = 1000;
typedef struct
{
    int y, x;
}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2]; //마지막 2는 벽 뚫기 여부
int BFS(void)
{
    queue < pair<pair<int, int>, int>> q; //y, x, 벽 뚫기
    q.push(make_pair(make_pair(0, 0), 1)); //시작점, 벽 뚫기 가능
    cache[0][0][1] = 1;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();
        //도착하면
        if (y == N - 1 && x == M - 1)
            return cache[y][x][block]; //시작하는 칸도 포함
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
            {
                //벽이 있고, 벽을 아직 안 뚫었다면
                if (graph[nextY][nextX] == 1 && block)
                {
                    cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), block - 1));
                }
                //벽이 없고 방문하지 않았던 곳이라면
                else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0)
                {
                    cache[nextY][nextX][block] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), block));

               }
            }
        }
    }
    return -1;
}
void BreakingWallAndMove()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            graph[i][j] = temp[j] - '0';
    }
    cout << BFS() << endl;
}

/*
	공부해야할 점
	1) tuple은 4개 이상도 가능. 이름 때문에 3개만 가능하다고 생각했다..
	2) visisted 배열을 선언하지 않고, 끝까지 못갔으면, (N,M)을 만나지도 않았으니 -1을 반환
	3) 행렬에 대한 개념!! 주의하자 
    4) MAX 를 상수로 정의해주는 테크닉
    5) ☆ 중요 ☆
    왜 visited를 3차원 배열로 선언해서 이전에 뚫어서 방문했는지, 안 뚫어서 방문했는지를 알아야 하는가??
    에 대한 고찰!!
*/