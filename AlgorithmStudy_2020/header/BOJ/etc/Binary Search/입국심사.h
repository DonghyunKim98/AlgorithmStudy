#include <bits/stdc++.h>
//3079번 문제
using namespace std;

void Entrance() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//input 심사대 n개 사람 m명
	int N, M;
	cin >> N >> M;
	vector<long long> vc(N);
	for (int i = 0; i < N; i++)
		cin >> vc[i];
	sort(vc.begin(), vc.end());
	long long int begin = 0, end = (long long)vc.back() * M;
	while (begin <= end) {
		long long sum = 0;
		long long int mid = (begin + end) / 2;
		//주어진 시간에선 얼마나 심사할 수 있는지 확인. ->나눈 몫
		for (int i = 0; i < vc.size(); i++)
			sum += mid / vc[i];
		if (sum < M)   begin = mid + 1;
		else end = mid - 1;
	}
	cout << begin;
}