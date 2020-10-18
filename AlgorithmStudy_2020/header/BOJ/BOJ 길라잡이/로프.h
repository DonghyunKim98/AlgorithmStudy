#include <bits/stdc++.h>
//2217번 문제
using namespace std;
vector<int> vc;
typedef long long ll;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	sort(vc.begin(), vc.end(),greater<int>());
	ll result=0;
	for (int i = 0; i < N; i++) {
		//i번째 rope까지 사용했을떄 버틸 수 있는 최대 합 => vc[i]*(i+1)
		ll sum = vc[i] * (i + 1);
		//기존에 버틸 수 있는 합보다 크다! 그럼 넣어~~
		if (sum > result) result = sum;
	}
	cout << result;
}

/*
	전형적인 그리디. 어렵다
*/