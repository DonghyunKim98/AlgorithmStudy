#include <bits/stdc++.h>
//11047번 문제
using namespace std;

void Coins() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; i++)
		cin >> coins.at(i);

	//동전의 가치가 오름차순 & 배수이므로 Greedy 가능
	int cnt = 0;
	while (true) {
		if (K == 0) break;
		if (coins.at(coins.size()-1) <= K) {
			K -= coins.at(coins.size()-1);
			cnt++;
		}
		else {
			coins.pop_back();
		}
	}
	cout << cnt;
}