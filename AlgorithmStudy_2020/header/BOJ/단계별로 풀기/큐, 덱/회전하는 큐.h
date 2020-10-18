#include <bits/stdc++.h>
//1021번 문제
using namespace std;

void SpinningQueue() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, count = 0;
	deque<int> dq;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (M > 0) {
		int target,target_index;
		cin >> target;
		//Find target index
		for (int i = 0; i < dq.size(); i++)
			if (dq.at(i) == target) {
				target_index = i;
				break;
			}

		while (true) {
			//front에서 찾았다.
			if (target_index==0 ||target_index==dq.size()) {
				dq.pop_front();
				break;
			}
			//front에서의 거리가 더 가깝다! => front에서 빼서 뒤로 넣는다 / target_index는 1개 준다.
			//dq.size 는 index보다 1이 많긴 하지만, 맨 마지막에 왔을때 한번더 앞으로 보내야 하기 떄문에 dq.size 그대로 간다.
			else if (abs(target_index) < abs(int(dq.size()- target_index))) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
				target_index--;
			}
			//back에서의 거리가 더 가깝다(또는 같다)! => back에서 빼서 앞으로 넣는다. /target_index는 1개 는다.
			else {
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
				target_index++;
			}
		}
		M--;
	}

	cout << count;
}