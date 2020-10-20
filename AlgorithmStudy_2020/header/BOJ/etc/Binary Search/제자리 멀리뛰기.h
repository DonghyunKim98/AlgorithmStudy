#include<bits/stdc++.h>
//6029�� ����
using namespace std;
int D, N, M;
vector<int> vc;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> D >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	vc.push_back(0), vc.push_back(D);
	sort(vc.begin(), vc.end());
	int start = 0, end=*(vc.end()-1);
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0, prev = vc[0];
		for (int i = 1; i < (int)vc.size(); i++) {
			int gap = vc[i] - prev;
			//�ּҰŸ��� mid���� �� �ڴٸ� �������� ����
			if (gap >= mid) {
				prev = vc[i];
			}
			//�� �ڴٸ� ������. prev ����
			else cnt++;
		}
		//�� ������ -> �ּ� ������ �ʹ� ŭ -> end�� �ٿ��� mid���� �ٿ���
		if (cnt > M) {
			end = mid - 1;
		}
		//�� ������ -> �ּ� ������ �ʹ� ���� -> start�� �÷��� mid���� �÷�����
		else {
			start = mid + 1;
			ans = mid;
		}

	}
	cout << ans;
}