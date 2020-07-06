#include <bits/stdc++.h>
//3079�� ����
using namespace std;

void Entrance() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//input �ɻ�� n�� ��� m��
	int N, M;
	cin >> N >> M;
	vector<long long> vc(N);
	for (int i = 0; i < N; i++)
		cin >> vc[i];
	sort(vc.begin(), vc.end());
	long long int begin = 0, end = (long long)vc.back() * M;
	while (begin <= end) {
		long long sum = 0;
		long long int mid = (begin + end) / 2;
		//�־��� �ð����� �󸶳� �ɻ��� �� �ִ��� Ȯ��. ->���� ��
		for (int i = 0; i < vc.size(); i++)
			sum += mid / vc[i];
		if (sum < M)   begin = mid + 1;
		else end = mid - 1;
	}
	cout << begin;
}