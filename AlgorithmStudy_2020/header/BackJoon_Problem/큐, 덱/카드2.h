#include <bits/stdc++.h>
//2164번 문제
using namespace std;

void Card() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}

/*
	FIFO 구조임을 알면 쉽게 풀수 있는 문제(push가 일어나는 곳과 pop이 일어나는 곳이 다름)
*/