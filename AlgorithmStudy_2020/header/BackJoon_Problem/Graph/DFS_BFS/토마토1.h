#include <bits/stdc++.h>

//7576번 문제 -> 풀었음
//BFS를 이용해야 함.
//https://sihyungyou.github.io/baekjoon-7576/ 참고
//segment는 큐에 들어있는 좌표들이 몇 개까지 하나의 턴으로 봐야하는지 기록하는 변수
//count는 다음 segment가 몇개인지 기록한다.
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
//토마토가 전부 익었는지 확인
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
    //처음부터 익힐 수 있는 토마토가 없는 경우
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
                //다음 토마토가 범위 안에 있고 안 익었을 경우에만
                if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N && tomato[nextY][nextX] == 0)
                {
                    tomato[nextY][nextX] = 1;
                    dq.push_back(make_pair(nextY, nextX));
                }
            }
            //익힐 수 있는 토마토를 전부 익혔고 전부 익었을 경우
            if (dq.size() == 0 && allRipe())
                return day;
            //익힐 수 있는 토마토는 전부 익혔지만 안 익은 토마토 존재
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
                dq.push_back(make_pair(i, j)); //익은 토마토는 덱에 넣는다
            else if (tomato[i][j] == -1)
                noTomato++; //토마토를 넣을 수 없는 칸
        }
    if (dq.size() == M * N - noTomato)
    {
        cout << 0 << endl; //모든 토마토 다 익었을 경우
    }
    else{
        int result = BFS();
        cout << result << endl;
    }
}

/*
	배워야 할 것
	1) count를 셀때 내일이면 1일걸려서 익은건데 count가 2가 되는 걸 피하는 프로그래밍
	2) output 을 내는 3가지 분기를 한번에 함수쪽에서 분기하지말고
       main 에서 일단 하나 분기하고 나머지 2개는 BFS 함수쪽에서 분기.
    3) (생각은 했지만) 같은 결과 값이 나왔더라도, 그 과정이 다를 수 있음
    이 문제에서 -1이 나오는 과정은 2가지. 
        (a):처음부터 익힐 수 있는 토마토가 없을 수도 있고
        (b):익혔는데 아직 익히지 않은 토마토가 있을 수도 있다.
    4) 조건자체가 복잡할 수도 있다. 이땐 bool 함수를 선언해서 확인하는것도 좋음
       이 문제에선 모든 토마토가 익었는지에 대한 것!
*/
