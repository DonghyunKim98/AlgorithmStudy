#include <bits/stdc++.h>
using namespace std;
int lab[8][8];
int tempLab[8][8];
int n, m, ans = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//���� ����
void mapCopy(int(*a)[8], int(*b)[8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}
//���̷��� ��Ʈ����(BFS)
void virusSpread() {
    //SpreadLab�� 3���� ������ ���� �� ���̷����� ������ ���� �������� ��Ȳ�� �����ϴ°�.
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
    //�����ҿ� �������� ���� �κ� üũ.
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (SpreadLab[i][j] == 0)
                cnt += 1;
        }
    }
    ans = max(ans, cnt);
}

//�� �����(���ȣ�� ���)
//�� �κ��� �ٽ� => BackTracking�� ����
void wall(int cnt) {
    //3���� ���� �������� ��, ���̷����� ��Ʈ����.
    if (cnt == 3) {
        virusSpread();
        return;
    }
    //�� ����� �κ�.
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
    //�����ҿ��� 0�� �κ��� ��� ���� ������ �ϹǷ� ������ ���� ����.
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

//�ᱹ 4�� ��ø�� ����