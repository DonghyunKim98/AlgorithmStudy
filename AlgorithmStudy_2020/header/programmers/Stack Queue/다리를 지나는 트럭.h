#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	//{Ʈ���� ����,�ٸ��� ���� ����� �ð�}
	vector <pair<int, int>> bridge;
	int total_weight = 0;

	//bridge�� �ϴ� �ϳ��� �ְ� ���� (while���� ����ϱ� ����)
	total_weight += truck_weights.front();
	bridge.push_back(make_pair(truck_weights.front(), 1));
	truck_weights.erase(truck_weights.begin());
	answer = 1;

	while (!bridge.empty()) {
		//bridge�� �ִ� Ʈ���� �ð� ���
		for (int i = 0; i < bridge.size(); i++)
			bridge.at(i).second++;

		//bridge�� �ִ� �� ���� Ʈ�� ��� ���� ����
		if (bridge.at(0).second > bridge_length) {
			total_weight -= bridge.at(0).first;
			bridge.erase(bridge.begin());
		}

		//truck�� ��⿭�� ���� ����.
		if (!truck_weights.empty()) {
			int current_truck = truck_weights.front();
			//���� bridge���� �ö� Ʈ���� ���ο� Ʈ���� ���Ը� ������ �� ��������
			if (total_weight + current_truck <= weight) {
				bridge.push_back(make_pair(current_truck, 1));
				truck_weights.erase(truck_weights.begin());
				total_weight += current_truck;
			}
		}
		answer++;
	}
	return answer;
}