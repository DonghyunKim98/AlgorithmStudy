#include <bits/stdc++.h>
using namespace std;
const int MAX = 30 + 1 + 1;
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	//reserve�� �ݵ�� ���������̶�� ������ �����Ƿ� ������������ sort
	sort(reserve.begin(), reserve.end());

	bool lost_arr[MAX];
	fill_n(lost_arr, MAX, false);
	//index�� �Ҿ���� ��� ǥ��
	for (int i = 0; i < lost.size(); i++)
		lost_arr[lost[i]] = true;

	int size = reserve.size();
	int idx = 0;
	for (int i = 0; i < size; i++) {
		int current_margin = reserve[idx];
		if (lost_arr[current_margin] == true) {
			lost_arr[current_margin] = false;
			answer++;
			reserve.erase(reserve.begin() + idx);
			idx--;
		}
		idx++;
	}

	//�ջ�� -> �޻��
	for (int i = 0; i < reserve.size(); i++) {
		int current_margin = reserve[i];
		if (lost_arr[current_margin - 1] == true) {
			lost_arr[current_margin - 1] = false;
			answer++;
		}
		else if (lost_arr[current_margin + 1] == true) {
			lost_arr[current_margin + 1] = false;
			answer++;
		}
	}

	return answer;
}