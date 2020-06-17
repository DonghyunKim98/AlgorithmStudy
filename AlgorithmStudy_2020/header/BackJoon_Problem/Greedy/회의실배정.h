#include <bits/stdc++.h>
//1931번 문제
using namespace std;

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		else return a.second > b.second;
	}
};

void MeetingRoom() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//{시작시간,종료시간} 기준 
	priority_queue <pair<int, int>, vector<pair<int, int>>, comp> pq;

	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		pq.push({ temp1,temp2 });
	}

	int cnt = 0 , elapsed_time = 0;
	while (!pq.empty()) {
		int current_start = pq.top().first;
		int current_end = pq.top().second;
		pq.pop();
		if (current_start < elapsed_time) continue;
		else {
			elapsed_time = current_end;
			cnt++;
		}
	}
	cout << cnt;
}

/*
	이벤트 스케쥴링 문제 => 알고리즘 트레이닝 55쪽.
*/