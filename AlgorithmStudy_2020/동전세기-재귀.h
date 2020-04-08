#include <bits/stdc++.h>

using namespace std;
//재귀함수 이용
int solve(int);

//동전의 종류가 모아져 있는 집합 s
set<int> coins;
//메모리제이션을 위한 배열
bool* ready = new bool[100]{0,};
int* value = new int[100]{0,};


void coin() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cout << "동전의 개수를 입력하세요" << endl;
	cin >>N;
	cout << "동전의 가치를 입력하세요" << endl;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	int Object;
	cout << "얼마를 맞추려고 합니까?" << endl;
	cin >> Object;
	cout << solve(Object) << endl;
	return ;
}

int solve(int x) {
	if (x < 0) return 1000000;
	if (x == 0) return 0;
	if (ready[x]) return value[x];
	int best = 1000000;
	for (auto c : coins) {
		best = min(best, solve(x - c) + 1);
		cout << best << endl;
	}
	ready[x] = true;
	value[x] = best;
	return best;
}