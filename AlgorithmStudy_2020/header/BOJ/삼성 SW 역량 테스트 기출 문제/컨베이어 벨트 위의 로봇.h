#include <bits/stdc++.h>
//20055�� ����
using namespace std;
typedef pair<bool, int> pbi;
const int MAX = 100 + 1;
int N, K;
vector<pbi> vc(2 * MAX + 1);
vector<int> robot;
queue<int> q;
bool process(int turn) {
	//1�� ���� -> ��ĭ ȸ��
	pbi temp = vc[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		vc[i] = vc[i - 1];
	}
	vc[1] = temp;

	for (int i = 0; i < robot.size(); i++) {
		robot[i]++;
		//�������� ��ġ�� �ִ� �κ� ����
		if (robot[i] == N) {
			vc[N].first = true;
			robot.erase(robot.begin() + i);
		}
	}

	//2�� ����
	bool isFirstEmpty = true;
	for (int i = 0; i < robot.size(); i++) {
		int curPos = robot[i];
		int next = curPos + 1;
		if (next == 2 * N + 1) next = 1;

		if (vc[next].second != 0 && vc[next].first == true) {
			vc[next].second--;
			if (next == N) robot.erase(robot.begin() + i); // �������� ��ġ�� �ִ� �κ� ����
			else {
				vc[next].first = false;
				robot[i] = next;
			}
		}
	}

	//3�� ����
	if (vc[1].first && vc[1].second) {
		robot.push_back(1);
		vc[1].second--;
		vc[1].first = false;
	}

	//4�� ����
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