#include <bits/stdc++.h>
//2798번 문제
using namespace std;

void BlackJack() {
	//setting
	int N, M;
	vector<int> card;
	//input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
	}

	//process =>Brutal Force (for 문 3번돌리기)
	int answer = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int temp = card[i] + card[j] + card[k];
				if (temp > M) continue;
				else answer = max(answer, temp);
			}
		}
	}

	//output
	cout << answer;
}
