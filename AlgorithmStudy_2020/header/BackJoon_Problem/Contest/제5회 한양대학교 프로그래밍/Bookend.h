#include <bits/stdc++.h>
//16465�� ����
using namespace std;
int N, M, L;
int arr[4];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> L;
	int total = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[temp]++;
		total += temp;
	}
	if (total > M || ((M - total) % L != 0 && (total % L != 0))) {
		cout << -1;
	}
	else cout << total / L;
}

/*
	vc�ȿ� �ִ� �������� �̿��ؼ�
	�� ���� L�� �ǰ� �ϸ� �ȴ�. (�׸��� ��Ȯ�� L�� �����ŭ ������ �Ѵ�.)

	�ٵ� å�� �ʺ� ���� 1,2,3��
*/