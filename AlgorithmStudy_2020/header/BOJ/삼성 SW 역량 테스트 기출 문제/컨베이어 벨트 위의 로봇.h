#include <bits/stdc++.h>
//20055번 문제
using namespace std;
typedef pair<bool, int> pbi;
const int MAX = 100 + 1;
int N, K;
vector<pbi> vc(2 * MAX + 1);
vector<int> robot;
queue<int> q;
bool process(int turn) {
	//1번 과정 -> 한칸 회전
	pbi temp = vc[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		vc[i] = vc[i - 1];
	}
	vc[1] = temp;

	for (int i = 0; i < robot.size(); i++) {
		robot[i]++;
		//내려가는 위치에 있는 로봇 삭제
		if (robot[i] == N) {
			vc[N].first = true;
			robot.erase(robot.begin() + i);
		}
	}

	//2번 과정
	bool isFirstEmpty = true;
	for (int i = 0; i < robot.size(); i++) {
		int curPos = robot[i];
		int next = curPos + 1;
		if (next == 2 * N + 1) next = 1;

		if (vc[next].second != 0 && vc[next].first == true) {
			vc[next].second--;
			if (next == N) robot.erase(robot.begin() + i); // 내려가는 위치에 있는 로봇 삭제
			else {
				vc[next].first = false;
				robot[i] = next;
			}
		}
	}

	//3번 과정
	if (vc[1].first && vc[1].second) {
		robot.push_back(1);
		vc[1].second--;
		vc[1].first = false;
	}

	//4번 과정
	int ret = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (vc[i].second <= 0) ret++;
	}
	return ret < K;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> vc[i].second;
		vc[i].first = true;
	}

	int cnt = 1;
	while (1) {
		if (!process(cnt)) break;
		cnt++;
	}
	cout << cnt;
}