#include <bits/stdc++.h>
using namespace std;
int lab[8][8];
int tempLab[8][8];
int n, m, ans = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//지도 복사
void mapCopy(int(*a)[8], int(*b)[8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}
//바이러스 퍼트리기(BFS)
void virusSpread() {
    //SpreadLab은 3개의 벽으로 막은 후 바이러스가 퍼졌을 때의 연구소의 상황을 저장하는곳.
    int SpreadLab[8][8];
    mapCopy(SpreadLab, tempLab);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (SpreadLab[i][j] == 2)
                q.push(make_pair(i, j));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (SpreadLab[nx][ny] == 0) {
                    SpreadLab[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    //연구소에 오염되지 않은 부분 체크.
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (SpreadLab[i][j] == 0)
                cnt += 1;
        }
    }
    ans = max(ans, cnt);
}

//벽 세우기(재귀호출 사용)
//이 부분이 핵심 => BackTracking의 구현
void wall(int cnt) {
    //3개의 벽이 세워졌을 때, 바이러스를 퍼트린다.
    if (cnt == 3) {
        virusSpread();
        return;
    }
    //벽 세우는 부분.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempLab[i][j] == 0) {
                tempLab[i][j] = 1;
                wall(cnt + 1);
                //BackTracking
                tempLab[i][j] = 0;
            }
        }
    }
}

void solution() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &lab[i][j]);
        }
    }
    //연구소에서 0인 부분을 모두 벽을 세워야 하므로 다음과 같이 진행.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                mapCopy(tempLab, lab);
                tempLab[i][j] = 1;
                wall(1);
                tempLab[i][j] = 0;
            }
        }
    }
    printf("%d\n", ans);
}

//결국 4중 중첩은 같음