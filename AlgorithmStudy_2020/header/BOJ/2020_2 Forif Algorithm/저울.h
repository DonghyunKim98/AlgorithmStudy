#include <bits/stdc++.h>
// 2437�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> vc;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	sort(vc.begin(), vc.end());
	int ans = 1;
	// �� ó���� 1�� �ƴ϶�� �翬�� 1�� ����
	if (vc[0] == 1) {
		// �������� ������
		int acc = vc[0];
		// ������ + 1 > vc[i] ���� ������� ��
		for (int i = 1; i < vc.size() && acc + 1>vc[i] - 1; i++) {
			acc += vc[i];
		}
		ans = acc + 1;
	}

	cout << ans;
}