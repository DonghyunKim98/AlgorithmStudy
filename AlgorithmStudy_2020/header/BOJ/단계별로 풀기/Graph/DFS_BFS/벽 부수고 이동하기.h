#include <bits/stdc++.h>
//2206�� ���� -> Ǯ����(O)
//https://yabmoons.tistory.com/73 ����
//https://jaimemin.tistory.com/650 ����
using namespace std;
const int MAX = 1000;
typedef struct
{
    int y, x;
}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2]; //������ 2�� �� �ձ� ����
int BFS(void)
{
    queue < pair<pair<int, int>, int>> q; //y, x, �� �ձ�
    q.push(make_pair(make_pair(0, 0), 1)); //������, �� �ձ� ����
    cache[0][0][1] = 1;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();
        //�����ϸ�
        if (y == N - 1 && x == M - 1)
            return cache[y][x][block]; //�����ϴ� ĭ�� ����
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
            {
                //���� �ְ�, ���� ���� �� �վ��ٸ�
                if (graph[nextY][nextX] == 1 && block)
                {
                    cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), block - 1));
                }
                //���� ���� �湮���� �ʾҴ� ���̶��
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
	�����ؾ��� ��
	1) tuple�� 4�� �̻� ����. �̸� ������ 3���� �����ϴٰ� �����ߴ�..
	2) visisted �迭�� �������� �ʰ�, ������ ��������, (N,M)�� �������� �ʾ����� -1�� ��ȯ
	3) ��Ŀ� ���� ����!! �������� 
    4) MAX �� ����� �������ִ� ��ũ��
    5) �� �߿� ��
    �� visited�� 3���� �迭�� �����ؼ� ������ �վ �湮�ߴ���, �� �վ �湮�ߴ����� �˾ƾ� �ϴ°�??
    �� ���� ����!!
*/