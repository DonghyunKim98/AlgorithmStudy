#include <bits/stdc++.h>
//20055번 문제
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100 + 1;
int N, K;
vector<int> vc(2 * MAX + 1);
bool visit[2 * MAX + 1];
queue<int> robot;

bool process() { 
	//1번과정
	//벨트 옮기기
	int temp = vc[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		vc[i] = vc[i - 1];
	}
	vc[1] = temp;
	int size = robot.size();
	for (int i = 0; i < size; i++) {
		int cur = robot.front();
		robot.pop();
		visit[cur] = false;
		if (cur + 1 != N) {
			visit[cur + 1] = true;
			robot.push(cur + 1);
		}
	}

	//2번과정
	//로봇 움직이기
	size = robot.size();
	for (int i = 0; i < size; i++) {
		int cur = robot.front();
		robot.pop();
		//다음으로 움직이긴 위해선, 다음 컨베이어 벨트의 내구도가 0이 아니고 벨트위에 로봇이 없어야함
		if (vc[cur + 1] != 0 && visit[cur + 1] == false) {
			visit[cur] = false;
			vc[cur + 1]--;
			if (cur + 1 != N) {
				visit[cur + 1] = true;
				robot.push(cur + 1);
			}
		}
		else robot.push(cur);
	}
	
	//3번과정
	//로봇 올리기
	if (vc[1] != 0 && visit[1] == false) {
		visit[1] = true;
		vc[1]--;
		robot.push(1);
	}

	//4번과정
	//내구도 확인
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (vc[i] == 0) cnt++;
	}
	return cnt < K;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> vc[i];
	}
	memset(visit, false, sizeof(visit));
	int cnt = 1;
	while (1) {
		if (!process()) break;
		cnt++;
	}
	cout << cnt;
}

/*
	1. 너무 "주어진 순서대로" 를 구현할려고 들어간 순서까지 저장된 자료구조를 만들려고 했다.
	   실상은 큐를 쓰면 되는데 말이다.
	2. 또 역시, "벨트의 내구도" 와 "벨트 위에 로봇이 있는지 여부" 를 너무 합칠려고 했다.
	   실상은 그냥 배열 2개 만들면 되는데 말이다.

	문제를 다시 정리하면, 문제를 풀어나가는데 필요한 정보는 4가지이다.
	1) 벨트의 내구도
	2) 벨트위에 장난감 여부
	3) 장난감의 위치
	4) 장난감이 들어간 순서

	이 4가지를 굳이 한번에 처리안해도 된다. 차근차근 구현해도 좋을 것 같다.
*/