#include <bits/stdc++.h>
//11729번 문제
using namespace std;

vector<pair<int, int>> v;
//from 탑에서 to 탑으로 by를 이용해서
void Recursion(int number, int from , int by , int to) {
	if (number == 1) v.push_back(make_pair(from, to));

	else {
		//from 탑에서 by탑으로 number-1개를 to를 이용해서
		Recursion(number - 1, from, to, by);
		v.push_back(make_pair(from, to));
		Recursion(number - 1, by, from, to);
	}
}

void Hanoi() {
	int N;
	cin >> N;
	Recursion(N,1,2,3);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).first << ' ' << v.at(i).second << '\n';
	}
}


/*
	(알고리즘 설명)
	0. A탑에서 C탑으로 N개를 옮기는 방법은..
		1. A 탑에서 B 탑으로 N-1개를 옮긴다.
		2. A 탑에서 가장 큰 원판을 C로 옮긴다.
		3. B 탑에서 N-1개를 이제 C로 옮긴다.
	1. 그럼 이제 B탑에서 N-1개를 C로 옮기는 방법은... =>재귀
*/