#include <bits/stdc++.h>
//16471�� ����
using namespace std;
int N;
vector<int> vc1, vc2;
void solution(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc1.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc2.push_back(temp);
	}

	sort(vc1.rbegin(), vc1.rend());
	sort(vc2.rbegin(), vc2.rend());
	int ans = 0, idx1 = 0, idx2 = 0;
	while (idx1 < N && idx2 < N) {
		//���� �̱� �� �ִ� ���ڰ� ��������
		if (vc1[idx1] < vc2[idx2]) {
			ans++, idx1++, idx2++;
		}
		else idx1++;
	}
	if (ans < (N + 1) / 2) cout << "NO";
	else cout << "YES";
}

/*
	���� �̻��� �̰ܾ� �Ѵ�.
	vc2�� �ִ� ���ڵ��� vc1�� �ִ� ���ڵ��� �̱�� �ִ����� Ȯ��.

	->����԰� �� ��� ������������ idx=0 ���� ���ؼ�
	  ���� ���� ū ���ڷ� �̱� �� �ִ� ���� ū ���ڸ� �̰ܾ���
*/