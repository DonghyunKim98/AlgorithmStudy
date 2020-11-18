#include <bits/stdc++.h>
using namespace std;
#define firstYpos first.first
#define firstXpos first.second
#define secondYpos second.first
#define secondXpos second.second
typedef pair<int, int> pii;
const int MAX = 100 + 1;
int N;
bool visited[4][MAX][MAX];
pii dir[] = { {0,1},{0,-1},{-1,0},{1,0} }; // 동서남북
bool inRange(vector<vector<int>>& borad,int ny, int nx) {
    if (0 <= ny && ny < N && 0 <= nx && nx < N) {
        if (borad[ny][nx] == 0) {
            return true;
        }
    }
    return false;
}

bool isEnd(pair<pii, pii> pos) {
    if (pos.firstYpos == N && pos.firstXpos == N) return true;
    if (pos.secondYpos == N && pos.secondXpos == N) return true;
    return false;
}

int BFS(vector<vector<int>> &borad) {
    memset(visited, false, sizeof(visited));
    queue < pair<pair<pii, pii>, int>> q;
    q.push({{ {0,0},{0,1} },1});
    visited[0][0][0] = visited[1][0][1] = true;
    while (q.empty()) {
        pair<pii,pii> curPos = q.front().first; 
        int cnt = q.front().second;
        q.pop();
        if (isEnd(curPos)) return cnt;
        // 4방향으로 전진
        for (int k = 0; k < 4; k++) {
            int firstNy = curPos.firstYpos + dir[k].first;
            int firstNx = curPos.firstXpos + dir[k].second;
            int secondNy = curPos.secondYpos + dir[k].first;
            int secondNx = curPos.secondXpos + dir[k].second;
            if (inRange(borad, firstNy, firstNx) && inRange(borad, secondNy, secondNx)) {
                q.push({ {{firstNy,firstNx},{secondNy,secondNx}},cnt + 1 });
            }
        }
        // 4방향으로 회전
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    return BFS(board);
}