#include <bits/stdc++.h>
//11399�� ����
using namespace std;

void ATM() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//���ڰ� ���� ������ (��������) ��ġ�Ǿ� ��
	priority_queue <int,vector<int>,greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int total = 0;
	for (int i = 0; i < N; i++) {
		total += pq.top() * (N - i);
		pq.pop();
	}
	cout << total;
}