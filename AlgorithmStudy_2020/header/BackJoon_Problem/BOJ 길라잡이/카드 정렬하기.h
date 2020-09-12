#include <bits/stdc++.h>
//1715¹ø ¹®Á¦
using namespace std;
int N;
priority_queue<int,vector<int>,greater<int>> pq;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	int ans=0;
	while (pq.size() > 1) {
		int num1 = pq.top(); pq.pop();
		int num2 = pq.top(); pq.pop();
		ans += (num1 + num2);
		pq.push(num1 + num2);
	}
	cout << ans;
}