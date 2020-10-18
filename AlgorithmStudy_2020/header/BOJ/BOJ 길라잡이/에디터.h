#include <bits/stdc++.h>
//1406번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	list<char> l;
	cin >> s;
	for (int i = 0; i < s.size(); i++) l.push_back(s[i]);
	list<char>::iterator cursor = l.end();
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		char order;
		cin >> order;
		if (order == 'P') {
			char temp;
			cin >> temp;
			l.insert(cursor, temp);
		}
		else if (order == 'L') {
			if (cursor != l.begin()) cursor--;
		}
		else if (order == 'D') {
			if (cursor != l.end()) cursor++;
		}
		else if (order == 'B') {
			if (cursor != l.begin()) {
				//cursor-1 비허용
				cursor = l.erase(--cursor);
			}
		}
	}
	for (list<char>::iterator iter = l.begin(); iter != l.end(); iter++) cout << *iter;
}

/*
	iterator 과 관련된 간단한 문제
*/