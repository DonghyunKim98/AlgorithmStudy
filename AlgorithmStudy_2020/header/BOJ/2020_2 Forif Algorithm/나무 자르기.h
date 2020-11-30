#include <bits/stdc++.h>
// 2805�� ����
using namespace std;
typedef long long ll;
int N, M;
vector<ll> vc;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	ll MAX = 0;
	for (int i = 0; i < N; i++) {
		ll temp;
		cin >> temp;
		vc.push_back(temp);
		MAX = max(MAX, temp);
	}
	ll begin = 0, end = MAX;
	while (begin <= end) {
		ll mid = (begin + end) / 2;
		ll wood = 0;
		for (int i = 0; i < vc.size(); i++) {
			if (vc[i] > mid) wood += vc[i] - mid;
		}
		// �� �߶���� => ���̰� �������� ��
		if (wood < M) {
			end = mid - 1;
		}
		// ���� �ڸ� => ���̰� ����������
		else {
			begin = mid + 1;
		}
	}
	cout << end;

}