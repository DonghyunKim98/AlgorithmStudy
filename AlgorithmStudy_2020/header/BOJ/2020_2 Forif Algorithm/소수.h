#include <bits/stdc++.h>
// 1312�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B, N;
	cin >> A >> B >> N;
	while (true) {
		N--;
		A %= B;
		A *= 10; // �ڿ� 0 ���̱� -> �Ҽ����� �������ϱ�
		if (N == 0) {
			cout << A / B;
			return;
		}
	}
}
/*
	������ �� �������� ������
	O(n) ���� Ǫ�°ǰ�?
*/