#include <bits/stdc++.h>
//10845¹ø ¹®Á¦
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	queue<int> q;
	while (N--) {
		string temp;
		cin >> temp;
		if (temp == "push") {
			int temp_int;
			cin >> temp_int;
			q.push(temp_int);
		}
		else if (temp == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (temp == "size") {
			cout << q.size() << '\n';
		}
		else if (temp == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (temp == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
			else cout << -1 << '\n';
		}
		else if (temp == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
			else cout << -1 << '\n';
		}
	}
}