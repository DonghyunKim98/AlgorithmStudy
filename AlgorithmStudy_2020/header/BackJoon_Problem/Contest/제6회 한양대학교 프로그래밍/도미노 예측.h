#include <bits/stdc++.h>
//17943번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, Q;
	cin >> N >> Q;
	vector<int> arr(N);
	vector<int> brr(N + 1);
	brr[0] = 1;
	for (int i = 1; i <= N-1; i++) {
		cin >> arr[i];
		brr[i] = brr[i - 1] ^ arr[i];
	}

	while (Q > 0) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			int x, y;
			cin >> x >> y;
			cout << (brr[x-1] ^ brr[y-1])<<'\n';
		}
		else {
			int x, y, d;
			cin >> x >> y >> d;
			int temp = brr[x - 1] ^ brr[y - 1];
			cout << (temp ^ d)<<'\n';
		}
		Q--;
	}
}

/*
	알고리즘 포인트
	=> 어차피 n개 변수 n-1개 식 => 특정지어지지 못한다.
	그렇지만 xor자체는 변하지 않는다. 이점을 이용해서 a1을 임의의 숫자 1로 설정하는것!!

	=> xor의 역연산은 xor라는 것!
*/