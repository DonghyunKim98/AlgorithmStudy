#include <bits/stdc++.h>
//1300번 문제
//https://jaimemin.tistory.com/988 참고
using namespace std;

void KthNumber() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int begin = 1, end = K;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			//mid 보다 작은 j의 수(i*j <=mid)
			//N이 많이 커지면, mid/i가 N보다 커질 수 있음(j의 최대 값은 N이므로 N개를 초과할 수는 없음)
			cnt += min(mid / i, N); 
		if (cnt <= K)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	cout << begin;
}

/*
	1 2 3
	2 4 6  => 1 2 2 3 3 4 '6' 6 9
	3 6 9

	무식하게 넣어서 그 자리를 실제로 구하는것은 실패
	그럼 어쩌지?

	알고리즘 포인트
	=> 순회하면서 개수를 구하는게 아닌, 배열에 들어간 수가 i*j임을 이용
	=> '몫'이라는 개념을 이용하면 한번에 셀 수 있음.
	=> 마지막에 출력하는것은 begin
	why?) 
*/