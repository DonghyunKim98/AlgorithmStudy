#include <bits/stdc++.h>
//17938번 문제
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int position, T;
	cin >> position >> T;
	int t = 1, before = 0, after = 0, cnt = 0;
	for (int i = 1; i <= T; i++) {
		//현재 차례의 손의 개수 count.
		//처음부터 2*N까지는 손이 늘어나는 것이 1만큼 증가
		//2*N 이후부터는 -1씩 감소 -> 21번째줄 code
		cnt += t;
		//before 초기화
		before = after;
		//after 초기화 (cnt를 더해줌)
		after += cnt;
		//1->2*N 이 되었으면 -1씩 감소로 변화
		//2*N->1 이 되었으면 1씩 증가로 변화 (단 첫째항 제외)
		if (cnt == 2 * N || (cnt == 1 && i != 1))
			t = -t;
		//손이 한바퀴 돌면 2*N만큼 뺌으로서 position초기화
		if (after > 2 * N)
			after -= 2 * N;
	}
	//손은 2개이기 때문에 2로 나누어줘야함.
	after = (after + 1) / 2;
	before = (before + 1) / 2;

	/*
		N=5
		before = 4
		after =  2
		-> 걸린 사람들 : 5 1 2
	*/
	if (before > after) {
		if (position > before || position <= after)  cout << "Dehet YeonJwaJe ^~^";
		else  cout << "Hing...NoJam";
	}
	/*
		N=5
		before = 2
		after = 4
		-> 걸린 사람들 : 3,4
	*/
	else {
		if (before < position && position <= after) cout << "Dehet YeonJwaJe ^~^";
		else cout << "Hing...NoJam";
	}
}