#include <bits/stdc++.h>
//2667번 문제 -> 풀었음(O)
using namespace std;
//https://ldgeao99.tistory.com/413 참고

int place[26][26]; //0: 집이 아님 1:집임
int check[26][26] = {};//0: 방문안함 1:집의 numbering
int ans[25 * 25] = {}; //부지별 개수 저장
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N;

void DFS(int i, int j, int num) {
    check[i][j] = num;
    //4개의 방향 중에 갈 수 있는 곳 만 탐색.
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        //place의 최대값을 넘는지 검사
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

    // 모든 자리를 돌며 번호의 개수를 셈
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (place[i][j] == 1) {
                ans[check[i][j]] += 1;
            }
        }
    }

    //오름차순으로 정렬
    sort(ans + 1, ans + cnt + 1);
    //정답출력
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << "\n";
    }
}

/*
   공부해야 할 점
   1) 섬의 개수와 매우 유사한 문제. 다만 마지막에 컴포넌트마다 몇개의 노드가 있는지를 생각해야 하는 문제
   2) 인접 리스트나 행렬등을 굳이 생각안해도 된다!!
   3) 섬의 개수와는 달리 이건 단 한글자만 받아야하므로 scanf_s 를 활용해야만 함.
   4) ans[check[i][j]] += 1; -> 메모리 제한이 걸려있던 sort문제와 비슷한 알고리즘.
   5) cin 과 scanf 를 번갈아가면서 쓰지 말자.
   *오타가 너무 잦음. 집중을 해서 변수명을 바꾸거나 헷갈리지 않도록 조심하고 또 조심해야 함.
*/