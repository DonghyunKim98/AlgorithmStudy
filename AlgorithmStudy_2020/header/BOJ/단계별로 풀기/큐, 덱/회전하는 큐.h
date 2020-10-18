#include <bits/stdc++.h>
//1021�� ����
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
			//front���� ã�Ҵ�.
			if (target_index==0 ||target_index==dq.size()) {
				dq.pop_front();
				break;
			}
			//front������ �Ÿ��� �� ������! => front���� ���� �ڷ� �ִ´� / target_index�� 1�� �ش�.
			//dq.size �� index���� 1�� ���� ������, �� �������� ������ �ѹ��� ������ ������ �ϱ� ������ dq.size �״�� ����.
			else if (abs(target_index) < abs(int(dq.size()- target_index))) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
				target_index--;
			}
			//back������ �Ÿ��� �� ������(�Ǵ� ����)! => back���� ���� ������ �ִ´�. /target_index�� 1�� �´�.
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