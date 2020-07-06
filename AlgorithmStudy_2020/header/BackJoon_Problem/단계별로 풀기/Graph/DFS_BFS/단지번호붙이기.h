#include <bits/stdc++.h>
//2667�� ���� -> Ǯ����(O)
using namespace std;
//https://ldgeao99.tistory.com/413 ����

int place[26][26]; //0: ���� �ƴ� 1:����
int check[26][26] = {};//0: �湮���� 1:���� numbering
int ans[25 * 25] = {}; //������ ���� ����
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N;

void DFS(int i, int j, int num) {
    check[i][j] = num;
    //4���� ���� �߿� �� �� �ִ� �� �� Ž��.
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        //place�� �ִ밪�� �Ѵ��� �˻�
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            if (check[x][y] == 0 && place[x][y] == 1) {
                DFS(x, y, num);
            }
        }
    }
}
void HomeNumbering() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf_s("%d",&N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf_s("%1d", &place[i][j]);
        }
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (place[i][j] == 1 && check[i][j] == 0)
                DFS(i, j, ++cnt);
        }
    }

    // ��� �ڸ��� ���� ��ȣ�� ������ ��
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (place[i][j] == 1) {
                ans[check[i][j]] += 1;
            }
        }
    }

    //������������ ����
    sort(ans + 1, ans + cnt + 1);
    //�������
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << "\n";
    }
}

/*
   �����ؾ� �� ��
   1) ���� ������ �ſ� ������ ����. �ٸ� �������� ������Ʈ���� ��� ��尡 �ִ����� �����ؾ� �ϴ� ����
   2) ���� ����Ʈ�� ��ĵ��� ���� �������ص� �ȴ�!!
   3) ���� �����ʹ� �޸� �̰� �� �ѱ��ڸ� �޾ƾ��ϹǷ� scanf_s �� Ȱ���ؾ߸� ��.
   4) ans[check[i][j]] += 1; -> �޸� ������ �ɷ��ִ� sort������ ����� �˰���.
   5) cin �� scanf �� �����ư��鼭 ���� ����.
   *��Ÿ�� �ʹ� ����. ������ �ؼ� �������� �ٲٰų� �򰥸��� �ʵ��� �����ϰ� �� �����ؾ� ��.
*/