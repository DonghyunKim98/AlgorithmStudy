#include <bits/stdc++.h>
//17938번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	
	int position, T;
	cin >> position >> T;
	T %= 2 * N -1;

	int cnt_before = 0, cnt_after=0;
	for (int i = 1; i <= T; i++) {
		//현재 들어야 하는 팔의 개수
		int temp;
		if (i <= N) temp = i;
		else temp = 2 * N - i;
		if (i != T) cnt_before += temp;
		else cnt_after += (temp + cnt_before);
 	}
	//position이 N번째 위치했을때 예외처리
	if (position == N) {

	}
	else if (position * 2 <= ) {

	}

}