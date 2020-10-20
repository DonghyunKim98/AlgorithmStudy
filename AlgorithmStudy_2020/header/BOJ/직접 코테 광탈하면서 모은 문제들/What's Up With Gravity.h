#include <bits/stdc++.h>
//5827번 문제
using namespace std;
#define Top 0
#define Bottom 1
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
const int MAX = 505;
char MAP[MAX][MAX];
int N, M;
pii Captin;
int dx[2] = { -1,1 };
int dis[2][MAX][MAX];

struct cmp {
    bool operator()(pair<pii, pii>& a, pair<pii, pii>& b) { return a.second.first > b.second.first; }
};

void init() { for (int k = 0; k < 2; k++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dis[k][i][j] = INT_MAX; }

pair<pii, bool> falling(int ypos, int xpos, int gravity, int cnt) {
    if (MAP[ypos][xpos] == 'D') {
    cout << cnt;
    exit(0);
    }
    if (gravity == Bottom) {
        while (1) {
            ypos++;
            if (ypos == N)   break;
            else if (MAP[ypos][xpos] == 'D') {
                cout << cnt;
                exit(0);
            }
            else if (MAP[ypos][xpos] == '#') {
                if (dis[gravity][ypos - 1][xpos] > cnt) {
                    dis[gravity][ypos - 1][xpos] = cnt;
                    return { {ypos - 1,xpos},true };
                }
                else return { {-1,-1},false };
            }
        }
    }
    else {
        while (1) {
            ypos--;
            if (ypos == -1) break;
            else if (MAP[ypos][xpos] == 'D') {
                cout << cnt;
                exit(0);
            }
            else if (MAP[ypos][xpos] == '#') {
                if (dis[gravity][ypos + 1][xpos] > cnt) {
                    dis[gravity][ypos + 1][xpos] = cnt;
                    return { {ypos + 1,xpos},true };
                }
                else return { {-1,-1},false };
            }
        }
    }
    return { {-1,-1},false };
}

int BFS() {
    init();
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, cmp> pq;
    pq.push({ {Captin},{0,Bottom} });
    dis[Bottom][Captin.first][Captin.second] = 0;
    while (!pq.empty()) {
        pii cur = pq.top().first;
        int cnt = pq.top().second.first, gravity = pq.top().second.second;
        pq.pop();
        int ypos = cur.first, xpos = cur.second;
        if (dis[gravity][ypos][xpos] < cnt) continue;
        dis[gravity][ypos][xpos] = cnt;
        for (int k = 0; k < 2; k++) {
            int ny = ypos, nx = xpos + dx[k];
            if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
            if (MAP[ny][nx] == '#') continue;
            pair<pii, bool> temp = falling(ny, nx, gravity, cnt);
            if (temp.second) pq.push({ {temp.first}, {cnt,gravity} });
        }
        gravity = gravity ? Top : Bottom;
        pair<pii, bool> temp = falling(ypos, xpos, gravity, cnt + 1);
        if (temp.second) pq.push({ {temp.first}, {cnt + 1,gravity} });
    }
    return -1;
}

void solution() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            MAP[i][j] = temp[j];
            if (MAP[i][j] == 'C')
                Captin = { i,j };
        }
    }
    //초기 Captin값 falling 구현
    while (1) {
        Captin.first++;
        if (Captin.first == N) {
            cout << -1;
            return;
        }
        else if (MAP[Captin.first][Captin.second] == 'D') {
            cout << 0;
            return;
        }
        else if (MAP[Captin.first][Captin.second] == '#') {
            Captin.first -= 1;
            break;
        }
    }
    cout << BFS();
}

/*
    수많은 반례들
    1. 
    5 5
    ###D#
    #....
    C....
    #....
    ###.#
    => 같은 위치라도 중력이 다를 수 있음
    --------
    2.
    4 2
    C.
    ##
    .D
    ##
    => #이 나오면 일단 멈춰야함
    ---------
    3.
    2 2
    CD
    #.
    => 움직이고 나서 D를 체크하는 것이 아닌 바로 D를 체크해야함
    ---------
    4.
    2 2
    C.
    D.
    => 처음 Captin은 떨어트리고 시작해야함.
*/