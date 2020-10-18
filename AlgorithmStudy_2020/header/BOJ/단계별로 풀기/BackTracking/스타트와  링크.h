#include <bits/stdc++.h>
//14889�� ����
//https://wjdgus2951.tistory.com/82 ����
using namespace std;
const int MAX = 20 + 1;
bool chosen_start[MAX] = { false, };
int power_map[MAX][MAX];
int N;
int answer = INT_MAX;

void DFS(int current_person, int cnt) {
	// ������ ������� �ɷ�ġ ���
	if (cnt == N / 2) {
		/*start�� ������� true
		  link�� ������� false
		  �̸� �̿��ؼ� start�� link vector�� ���� push
		*/
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < N; i++) {
			if (chosen_start[i]) start.push_back(i);
			else link.push_back(i);
		}
		//start vector�� size�� link vector�� size�� ������ �����Ƿ� �ѹ��� ó���ص� ��.
		int start_stat = 0, link_stat = 0;
		for (int i = 0; i < start.size(); i++) {
			//j�� i��° ����������� üũ => ������ üũ�Ѵٰ� ����!
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
		//���� ������� ���� ����� ã�ƺ� ������ ����(DFS ����)
		for (int i = current_person+1; i < N; i++) {
			//�̹� ������� ������
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
	N => ¦��
	�밢�� �������� ����� �ߺ����� ���� -> �� Ž��
	�ΰ��� ������ ���������� �ɷ�ġ ���� �ּ�ȭ

	���� ó���� ���ø��� ���� ����
		1) ó������ index�� �����ؼ� ����Ϸ��� �ߴ�.
		-> �ϴ� ����� 2���� ������ ������ �� ������ ����ص� �Ǵµ� ���̴�.
		2) ��Ʈ��ŷ�� ���� ��Ȯ�� ����X
		-> ��� ����� ���� ���캸�� Brutal force�� �����̶�� ���� ������
		-> �ٸ� �߰��� �� �̻� �������� ������ Ž���� �������� �ʴ´ٴ� ���̴�.

	�� ������ ����� �� �ִ� �ٸ� ������ �˰���
	-> ������ ���
	-> ��Ʈ ������
*/