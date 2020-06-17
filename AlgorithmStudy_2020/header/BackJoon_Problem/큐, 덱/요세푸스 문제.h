#include <bits/stdc++.h>
//11866¹ø ¹®Á¦
using namespace std;

void Josephus() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	queue <int> q;
	queue <int> temp;

	for (int i = 1; i <= N; i++) 
		q.push(i);
	
	cout << '<';
	int count = 0;
	while (!q.empty()) {
		count++;
		if (count == K) {
			cout << q.front();
			q.pop();
			count = 0;
			if (!q.empty()) cout << ", ";
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	cout << '>';
	
}