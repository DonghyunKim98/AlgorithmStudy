#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) return a[1] < b[1];
	else return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int total = 0, time = -1;
	int size = jobs.size();
	sort(jobs.begin(), jobs.end(), comp);
	//{걸리는 시간,들어갔던 순간의 시간}
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int current = 0;
	int startTime = 0;
	while (true) {
		time++;
		//break 조건-> jobs도 다 비었고 pq도 더이상 없고 진행중인 작업도 없음.
		if (jobs.empty() && pq.empty()&&current==0) break;
		//현재 시점부터 대기타야 하는 게 있다면 넣어준다.
		if (!jobs.empty()) {
			while (jobs[0][0] == time) {
				pq.push(make_pair(jobs[0][1], time));
				jobs.erase(jobs.begin());
				if (jobs.empty()) break;
			}
		}
		//현재 진행중인 작업수행.
		if (current != 0) {
			current--;
			//이번 작업으로 작업을 다 수행했다면 걸린시간을 total에 더함.
			if (current == 0)
				total += time - startTime;
		}
		//현재 진행중인 작업이 없다면(current가 0이라면) 작업을 수행(pq에 들어있는) 하게 함.
		if(current==0 && !pq.empty()) {
			startTime = time;
			current = pq.top().first;
			//대기시간을 total에 더해준다.
			total += (time - pq.top().second);
			pq.pop();
		}
	}
	return total / size;
}

/*
	디버깅은 강력한 힘을 가지고 있다.
*/