#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> pq_min;
	priority_queue<int> pq_max;
	int size = 0;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			pq_min.push(stoi(operations[i].substr(2, operations[i].size() - 2)));
			pq_max.push(stoi(operations[i].substr(2, operations[i].size() - 2)));
			size++;
		}
		else {
			if (size == 0) {
				continue;
			}
			if (operations[i][2] == '1') {
				pq_max.pop();
				size--;
			}
			else {
				pq_min.pop();
				size--;
			}

			//size가 줄어든 다음 size가 0이라면.
			if (size == 0) {
				while (!pq_min.empty()) pq_min.pop();
				while (!pq_max.empty()) pq_max.pop();
			}
		}
	}
	if (size == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (size == 1) {
		answer.push_back(pq_max.top());
		answer.push_back(pq_max.top());
	}
	else {
		answer.push_back(pq_max.top());
		answer.push_back(pq_min.top());
	}
	return answer;
}

/*
	예외처리 하는 곳 -> 변곡점부분(?)에 해당하는 size가 0이 되는 순간!
*/