#include <bits/stdc++.h>
//15686번 문제
using namespace std;
int N, M;
const int MAX = 50 + 1;
typedef struct {
	int ypos, xpos;
}point;

int arr[MAX][MAX];
vector<point> chicken, home;
vector<point> yes_chicken;
int answer = 987654321;

int Count() {
	int ret = 0;
	for (int i = 0; i < home.size(); i++) {
		int temp = 987654321;
		for (int j = 0; j < yes_chicken.size(); j++) {
			int temp2 = abs(home[i].ypos - yes_chicken[j].ypos) + abs(home[i].xpos - yes_chicken[j].xpos);
			temp = min(temp2, temp);
		}
		ret += temp;
	}
	return ret;
}

void DFS(int idx, int depth) {
	if (depth == M) {
		int temp = Count();
		answer = min(temp, answer);
		return;
	}
	for (int k = idx; k < chicken.size(); k++) {
		yes_chicken.push_back(chicken[k]);
		DFS(k + 1, depth + 1);
		yes_chicken.erase(yes_chicken.end() - 1);
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) home.push_back({ i,j });
			else if (arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	DFS(0, 0);
	cout << answer;
}


/*
	알고리즘 포인트
	1. 치킨집은 조합으로 빼야함
*/