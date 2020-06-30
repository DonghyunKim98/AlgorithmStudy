#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	//{트럭의 무게,다리에 온지 경과한 시간}
	vector <pair<int, int>> bridge;
	int total_weight = 0;

	//bridge에 일단 하나는 넣고 시작 (while문을 통과하기 위함)
	total_weight += truck_weights.front();
	bridge.push_back(make_pair(truck_weights.front(), 1));
	truck_weights.erase(truck_weights.begin());
	answer = 1;

	while (!bridge.empty()) {
		//bridge에 있는 트럭들 시간 경과
		for (int i = 0; i < bridge.size(); i++)
			bridge.at(i).second++;

		//bridge에 있는 맨 앞의 트럭 통과 여부 결정
		if (bridge.at(0).second > bridge_length) {
			total_weight -= bridge.at(0).first;
			bridge.erase(bridge.begin());
		}

		//truck이 대기열에 있을 때만.
		if (!truck_weights.empty()) {
			int current_truck = truck_weights.front();
			//현재 bridge위에 올라간 트럭에 새로운 트럭의 무게를 감당할 수 있을때만
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