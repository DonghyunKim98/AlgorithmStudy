#include <bits/stdc++.h>
//11653�� ����
using namespace std;
const int MAX = 10000000 + 1;

void Facorization() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 2; i <= sqrt(N); i++) {
		while (N % i == 0) {
			cout << i<<'\n';
			N /= i;
		}
	}
	//ó������ �Ҽ����� ���°� ������
	if (N != 1) cout << N << '\n';
}

//�ð��� ���� 1��. O(n)�����ε� ����.