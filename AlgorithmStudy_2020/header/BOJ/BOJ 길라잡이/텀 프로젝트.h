#include <bits/stdc++.h>
//9466번 문제
//https://lmcoa15.tistory.com/51 참고
using namespace std;
const int MAX = 100000 + 1;
vector<int> student; //학생이 가리키는 다른 학생 번호
vector<int> first_student; //첫 번째로 dfs를 시작한 학생 번호
vector<int> visited; //방문 유무
int DFS(int start, int current, int cnt) {
	//또 방문한다면
	if (visited[current]) {
		//첫 번째로 dfs를 시작한 학생이 맞는지, 사이클이 맞는지
		//즉 처음으로 사이클을 찾은것인지
		if (first_student[current] != start) return 0;

		//사이클에 해당되는 학생 수
		return cnt - visited[current];
	}
	first_student[current] = start;
	visited[current] = cnt;
	return DFS(start, student[current], cnt + 1);

}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T,N;
	cin >> T;
	while (T--) {
		cin >> N;
		student = vector<int>(N + 1, 0);
		first_student = vector<int>(N + 1, 0);
		visited = vector<int>(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> student[i];
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				ans += DFS(i, i, 1);
			}
		}
		cout << N - ans << '\n';
	}
}

/*
	사이클을 이루는가?? 에 대한 것.

	알고리즘 포인트
	1. 이전에 찾은 사이클을 어떻게 저장할 것인가?? 에 대한 문제.
	   처음엔 백터에 저장해서 사이클을 찾은 직후에 넣는 식으로 생각했는데, 인자로 넘기기도 어렵고 저장하는 것도 어려움
	   => 이를 해결하기 위해서 'DFS를 시작한 노드를 저장한다!' 라는 개념
	   => 그럼 같은 사이클을 2번 찾지는 않을 것이니깐.
	   => 물론 이 방법은 메모리가 많이 잡아먹긴한다.
*/