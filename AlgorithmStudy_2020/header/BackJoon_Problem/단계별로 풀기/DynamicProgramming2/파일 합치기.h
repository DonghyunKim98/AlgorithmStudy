#include <bits/stdc++.h>
//11066¹ø ¹®Á¦
using namespace std;

void FileMerge() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int K;
		cin >> K;
		priority_queue <int,vector<int>,greater<int>> pq;
		for (int i = 0; i < K; i++) {
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		int answer = 0;
		while (pq.size()>1) {
			int first = pq.top(); pq.pop();
			int second = pq.top(); pq.pop();
			answer += (first + second);
			pq.push(first+second);
		}
		cout << answer << '\n';
		T--;
	}
}