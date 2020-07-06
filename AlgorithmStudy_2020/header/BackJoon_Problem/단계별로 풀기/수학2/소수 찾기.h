#include <bits/stdc++.h>
//1978�� ����
using namespace std;


void Prime() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//�ϴ� ��� �Ҽ��� �˻�.
	bool prime_number[1001];
	fill_n(prime_number, 1001, true);
	//1�� ����
	prime_number[1] = false;
	for (int i = 2; i <= 1000; i++) {
		//�̹� �Ҽ��� �ƴѰ� �Ǹ����� ������ pass
		if (prime_number[i] == false) continue;
		//i ������ ������ i*2 ���� �Ҽ��� �ƴϹǷ� false���� �־��ش�.
		for (int j = i * 2; j <= 1000; j += i) {
			prime_number[j] = false;
		}
	}

	int total = 0;
	while (N > 0) {
		int temp;
		cin >> temp;
		if (prime_number[temp] == true) total += 1;
		N--;
	}

	cout << total;
}