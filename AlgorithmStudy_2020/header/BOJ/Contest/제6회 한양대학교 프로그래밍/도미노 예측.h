#include <bits/stdc++.h>
//17943�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	cin >> N >> Q;
	vector<int> arr(N);
	vector<int> brr(N + 1);
	brr[0] = 1;
	for (int i = 1; i <= N-1; i++) {
		cin >> arr[i];
		brr[i] = brr[i - 1] ^ arr[i];
	}

	while (Q > 0) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			int x, y;
			cin >> x >> y;
			cout << (brr[x-1] ^ brr[y-1])<<'\n';
		}
		else {
			int x, y, d;
			cin >> x >> y >> d;
			int temp = brr[x - 1] ^ brr[y - 1];
			cout << (temp ^ d)<<'\n';
		}
		Q--;
	}
}

/*
	�˰��� ����Ʈ
	=> ������ n�� ���� n-1�� �� => Ư���������� ���Ѵ�.
	�׷����� xor��ü�� ������ �ʴ´�. ������ �̿��ؼ� a1�� ������ ���� 1�� �����ϴ°�!!

	=> xor�� �������� xor��� ��!
*/