#include <bits/stdc++.h>

using namespace std;
//����Լ� �̿�
int solve(int);

//������ ������ ����� �ִ� ���� s
set<int> coins;
//�޸����̼��� ���� �迭
bool* ready = new bool[100]{0,};
int* value = new int[100]{0,};


void coin() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cout << "������ ������ �Է��ϼ���" << endl;
	cin >>N;
	cout << "������ ��ġ�� �Է��ϼ���" << endl;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	int Object;
	cout << "�󸶸� ���߷��� �մϱ�?" << endl;
	cin >> Object;
	cout << solve(Object) << endl;
	return ;
}

int solve(int x) {
	if (x < 0) return 1000000;
	if (x == 0) return 0;
	if (ready[x]) return value[x];
	int best = 1000000;
	for (auto c : coins) {
		best = min(best, solve(x - c) + 1);
		cout << best << endl;
	}
	ready[x] = true;
	value[x] = best;
	return best;
}