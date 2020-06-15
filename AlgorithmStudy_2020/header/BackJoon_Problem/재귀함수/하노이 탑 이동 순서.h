#include <bits/stdc++.h>
//11729�� ����
using namespace std;

vector<pair<int, int>> v;
//from ž���� to ž���� by�� �̿��ؼ�
void Recursion(int number, int from , int by , int to) {
	if (number == 1) v.push_back(make_pair(from, to));

	else {
		//from ž���� byž���� number-1���� to�� �̿��ؼ�
		Recursion(number - 1, from, to, by);
		v.push_back(make_pair(from, to));
		Recursion(number - 1, by, from, to);
	}
}

void Hanoi() {
	int N;
	cin >> N;
	Recursion(N,1,2,3);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).first << ' ' << v.at(i).second << '\n';
	}
}


/*
	(�˰��� ����)
	0. Až���� Cž���� N���� �ű�� �����..
		1. A ž���� B ž���� N-1���� �ű��.
		2. A ž���� ���� ū ������ C�� �ű��.
		3. B ž���� N-1���� ���� C�� �ű��.
	1. �׷� ���� Bž���� N-1���� C�� �ű�� �����... =>���
*/