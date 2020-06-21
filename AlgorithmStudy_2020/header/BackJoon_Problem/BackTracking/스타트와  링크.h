#include <bits/stdc++.h>
//14889번 문제
//https://wjdgus2951.tistory.com/82 참고
using namespace std;
const int MAX = 20 + 1;
bool chosen_start[MAX] = { false, };
int power_map[MAX][MAX];
int N;
int answer = INT_MAX;

void DFS(int current_person, int cnt) {
	// 절반을 골랐으면 능력치 계산
	if (cnt == N / 2) {
		/*start에 골랐으면 true
		  link에 골랐으면 false
		  이를 이용해서 start와 link vector에 각각 push
		*/
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < N; i++) {
			if (chosen_start[i]) start.push_back(i);
			else link.push_back(i);
		}
		//start vector의 size와 link vector의 size는 어차피 같으므로 한번에 처리해도 됨.
		int start_stat = 0, link_stat = 0;
		for (int i = 0; i < start.size(); i++) {
			//j는 i번째 다음사람부터 체크 => 조합을 체크한다고 생각!
			for (int j = i + 1; j < start.size(); j++) {
				int start_first = start.at(i), start_second = start.at(j);
				int link_first = link.at(i), link_second = link.at(j);
				start_stat += power_map[start_first][start_second] + power_map[start_second][start_first];
				link_stat += power_map[link_first][link_second] + power_map[link_second][link_first];
			}
		}
		answer=min(answer,abs(start_stat - link_stat));
		return;
	}
	else {
		//현재 사람보다 이전 사람은 찾아볼 이유가 없음(DFS 구조)
		for (int i = current_person+1; i < N; i++) {
			//이미 골랐으면 빠지고
			if (chosen_start[i]) continue;
			chosen_start[i] = true;
			DFS(i, cnt+1);
			//Back Tracking
			chosen_start[i] = false;
		}
	}
}



void StartLink() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power_map[i][j];
		}
	}
	//
	DFS(0, 0);
	cout << answer;
}

/*
	N => 짝수
	대각선 기준으로 행렬이 중복되지 않음 -> 다 탐색
	두개의 팀으로 나누었을때 능력치 차이 최소화

	내가 처음에 떠올리지 못한 이유
		1) 처음부터 index에 접근해서 계산하려고 했다.
		-> 일단 사람을 2개의 팀으로 나누고 그 다음에 계산해도 되는데 말이다.
		2) 백트래킹에 대한 정확한 이해X
		-> 모든 경우의 수를 살펴보는 Brutal force의 일종이라는 것을 몰랐다
		-> 다만 중간에 더 이상 유망하지 않으면 탐색을 진행하지 않는다는 것이다.

	이 문제에 적용될 수 있는 다른 종류의 알고리즘
	-> 수열적 사고
	-> 비트 연산자
*/