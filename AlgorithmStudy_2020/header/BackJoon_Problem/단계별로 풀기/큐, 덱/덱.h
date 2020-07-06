#include <bits/stdc++.h>
//10866¹ø ¹®Á¦
using namespace std;

void Deque() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	deque<int> dq;

	while (N > 0) {
		string temp;
		cin >> temp;

		if (temp == "push_front") {
			int temp_int;
			cin >> temp_int;
			dq.push_front(temp_int);
		}
		else if (temp == "push_back") {
			int temp_int;
			cin >> temp_int;
			dq.push_back(temp_int);
		}
		else if (temp == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (temp == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (temp == "size") {
			cout << dq.size() << '\n';
		}
		else if (temp == "empty") {
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (temp == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if (temp == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
		N--;
	}
}