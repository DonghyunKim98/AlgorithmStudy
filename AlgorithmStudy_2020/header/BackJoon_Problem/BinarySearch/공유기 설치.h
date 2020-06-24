#include <bits/stdc++.h>
//2110번 문제
using namespace std;

void RouterInstall() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, C;
	cin >> N >> C;
	vector<long long> vc(C);
	for (int i = 0; i < C; i++)
		cin >> vc.at(i);
	sort(vc.begin(), vc.end());


}

/*
	Brutal force => 조합. O(n!) 

*/