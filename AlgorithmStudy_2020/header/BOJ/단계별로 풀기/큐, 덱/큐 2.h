#include <bits/stdc++.h>
//18258¹ø ¹®Á¦
using namespace std;

void Queue() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if (temp == "push") {
			int temp_int;
			cin >> temp_int;
			q.push(temp_int);
		}
		else if (temp == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (temp == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
		else if (temp == "size") cout << q.size() << '\n';
		else if (temp == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (temp == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
	}
}