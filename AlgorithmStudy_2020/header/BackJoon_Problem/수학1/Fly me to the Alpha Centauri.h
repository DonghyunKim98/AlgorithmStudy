#include <bits/stdc++.h>
//1011��
//https://jm-park.github.io/algorithm/2018/08/01/%EB%B0%B1%EC%A4%80-1011%EB%B2%88-Fly-me-to-the-Alpha-Centauri.html ����
using namespace std;

void Fly() {
	int T;
	cin >> T;
	while (T > 0) {
		double x, y;
		cin >> x >> y;
		double i = 1, cnt = 0;

		// y-x���� ū ������i ���ϱ�
		for (;; i++) {
			if (i * i > y - x)
				break;
		}

		// y-x�� i-1�� �������� ��� 
		if ((i - 1) * (i - 1) == y - x)
			cnt = 2 * (i - 1) - 1;
		// i-1�� ������ < y-x <= �߰����� �� ���
		else if ((i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2) >= y - x)
			cnt = 2 * i - 2;
		// �߰����� < y-x < i�� ������ �� ���
		else
			cnt = 2 * i - 1;
		cout << cnt << "\n";
		T--;
	}
}