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
	//{�ɸ��� �ð�,���� ������ �ð�}
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int current = 0;
	int startTime = 0;
	while (true) {
		time++;
		//break ����-> jobs�� �� ����� pq�� ���̻� ���� �������� �۾��� ����.
		if (jobs.empty() && pq.empty()&&current==0) break;
		//���� �������� ���Ÿ�� �ϴ� �� �ִٸ� �־��ش�.
		if (!jobs.empty()) {
			while (jobs[0][0] == time) {
				pq.push(make_pair(jobs[0][1], time));
				jobs.erase(jobs.begin());
				if (jobs.empty()) break;
			}
		}
		//���� �������� �۾�����.
		if (current != 0) {
			current--;
			//�̹� �۾����� �۾��� �� �����ߴٸ� �ɸ��ð��� total�� ����.
			if (current == 0)
				total += time - startTime;
		}
		//���� �������� �۾��� ���ٸ�(current�� 0�̶��) �۾��� ����(pq�� ����ִ�) �ϰ� ��.
		if(current==0 && !pq.empty()) {
			startTime = time;
			current = pq.top().first;
			//���ð��� total�� �����ش�.
			total += (time - pq.top().second);
			pq.pop();
		}
	}
	return total / size;
}

/*
	������� ������ ���� ������ �ִ�.
*/