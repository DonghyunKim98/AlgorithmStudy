#include <bits/stdc++.h>
//2805번 문제
using namespace std;

void TreeCutting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	long long M;
	cin >> N >> M;
	vector<long long>vc;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}

	//parametric search
	sort(vc.begin(), vc.end());
	long long begin = 0, end = vc.at(vc.size()-1);
	/*long long result = -1;*/
	while (begin<=end) {
		long long k = (begin + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < vc.size(); i++)
			if (vc[i] > k) cnt += vc[i] - k;

		if (cnt >= M) { 
			/*if (result < k)
				result = k;*/
			begin = k + 1; 
		}
		else end = k - 1;
	}
	cout << end;

}

/*
	https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2805-%EB%82%98%EB%AC%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0
	=>upper_bound에 대한 이야기 (lower_bound가 아니라)
	즉 cnt>=M 일때, cnt==M일때의 lower bound를 구하기 위해서, 기존의 k값보다 작았다면 k을 갱신해주는 것.
	왜냐하면 begin이 계속 커질거니깐, k값이 계속 증가할것.
	그러다 begin==end 이면 (이때가 곧 while문 탈출하기 직전 loop) cnt==M을 만족시키는 가장 큰 k 값이니깐
	이때가 정답!
*/