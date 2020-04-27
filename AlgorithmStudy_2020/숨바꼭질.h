#include <bits/stdc++.h>

//1697번문제
//https://wkdtjsgur100.github.io/algo-1697/ 참고
using namespace std;
bool visited[100000] = { false, };
queue<pair<int, int>> q;
int N, K;

void BFS() {
	q.push(pair<int, int>(N, 0));
	while (!q.empty()) {
        int pos = q.front().first;
        int depth = q.front().second;

        if (pos == K)
            break;

        q.pop();

        visited[pos] = true;

        if (pos - 1 >= 0 && !visited[pos - 1])
            q.push(pair<int, int>(pos - 1, depth + 1));
        if (pos + 1 <= 100000 && !visited[pos + 1])
            q.push(pair<int, int>(pos + 1, depth + 1));
        if (pos * 2 <= 100000 && !visited[pos * 2])
            q.push(pair<int, int>(pos * 2, depth + 1));
	}
}

void HideandSeek(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
    BFS();
    cout << q.front().second << endl;
}

/*
    공부해야 할 점
    1) 특수한 조건들을 잘 생각해보자 (마치 DFS로 격자점을 세어나갔을 때 직사각형 밖으로 나가면 
    안되는 것처럼)
    -> 여기선 2배 곱하거나 한 값이 100000을 벗어날 수도 있다!
    2) 배열 3개를 100001값으로 선언하면, 메모리가 너무 크다. 차라리 큐를 pair형태로 선언
    3) 어차피 모든 노드가 가는 곳은 이미 알고 있으므로 굳이 인접리스트 작성 X
    4) 중간에 K를 딱 만나는 순간!! break를 걸어서 바로 거기서 depth를 출력!
*/