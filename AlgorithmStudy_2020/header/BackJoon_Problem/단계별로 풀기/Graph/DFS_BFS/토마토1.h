#include <bits/stdc++.h>

//7576�� ���� -> Ǯ����
//BFS�� �̿��ؾ� ��.
//https://sihyungyou.github.io/baekjoon-7576/ ����
//segment�� ť�� ����ִ� ��ǥ���� �� ������ �ϳ��� ������ �����ϴ��� ����ϴ� ����
//count�� ���� segment�� ����� ����Ѵ�.
using namespace std;
const int MAX = 1000;
class Dir{
public:
    int y, x;

};
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int tomato[MAX][MAX];
deque<pair<int, int>> dq;
int noTomato;
//�丶�䰡 ���� �;����� Ȯ��
bool allRipe(void)
{
    int possible = M * N - noTomato;
    int tomatoCnt = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (tomato[i][j] == 1)
                tomatoCnt++;
    return possible == tomatoCnt;
}
int BFS(void)
{
    int day = 0;
    //ó������ ���� �� �ִ� �丶�䰡 ���� ���
    if (dq.empty()) return -1;
    while (!dq.empty())
    {
        int currentSize = dq.size();
        for (int i = 0; i < currentSize; i++)
        {
            int y = dq.front().first;
            int x = dq.front().second;
            dq.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nextY = y + moveDir[i].y;
                int nextX = x + moveDir[i].x;
                //���� �丶�䰡 ���� �ȿ� �ְ� �� �;��� ��쿡��
                if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N && tomato[nextY][nextX] == 0)
                {
                    tomato[nextY][nextX] = 1;
                    dq.push_back(make_pair(nextY, nextX));
                }
            }
            //���� �� �ִ� �丶�並 ���� ������ ���� �;��� ���
            if (dq.size() == 0 && allRipe())
                return day;
            //���� �� �ִ� �丶��� ���� �������� �� ���� �丶�� ����
            else if (dq.size() == 0 && !allRipe())
                return -1;
        }
        day++;
    }
}
void Tomato()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                dq.push_back(make_pair(i, j)); //���� �丶��� ���� �ִ´�
            else if (tomato[i][j] == -1)
                noTomato++; //�丶�並 ���� �� ���� ĭ
        }
    if (dq.size() == M * N - noTomato)
    {
        cout << 0 << endl; //��� �丶�� �� �;��� ���
    }
    else{
        int result = BFS();
        cout << result << endl;
    }
}

/*
	����� �� ��
	1) count�� ���� �����̸� 1�ϰɷ��� �����ǵ� count�� 2�� �Ǵ� �� ���ϴ� ���α׷���
	2) output �� ���� 3���� �б⸦ �ѹ��� �Լ��ʿ��� �б���������
       main ���� �ϴ� �ϳ� �б��ϰ� ������ 2���� BFS �Լ��ʿ��� �б�.
    3) (������ ������) ���� ��� ���� ���Դ���, �� ������ �ٸ� �� ����
    �� �������� -1�� ������ ������ 2����. 
        (a):ó������ ���� �� �ִ� �丶�䰡 ���� ���� �ְ�
        (b):�����µ� ���� ������ ���� �丶�䰡 ���� ���� �ִ�.
    4) ������ü�� ������ ���� �ִ�. �̶� bool �Լ��� �����ؼ� Ȯ���ϴ°͵� ����
       �� �������� ��� �丶�䰡 �;������� ���� ��!
*/
