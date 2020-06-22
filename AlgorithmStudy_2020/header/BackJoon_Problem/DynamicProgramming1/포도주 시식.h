#include <bits/stdc++.h>
//2156번 문제
//https://mygumi.tistory.com/98 참고
using namespace std;

void WineTasting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long* juice = new long long[N + 1];
	for (int i = 1; i <= N; i++) cin >> juice[i];
	//Memoization
	long long arr[10000 + 1];
	//base case
	arr[0] = 0;
	arr[1] = juice[1];
	if (N >= 2) arr[2] = juice[1] + juice[2];
	//DP
	for (int i = 3; i <= N; i++) {
		//OXOO 의 경우 와 ?OXO의 경우를 따져준다.
		arr[i] = max(arr[i - 3] + juice[i - 1] + juice[i], arr[i - 2] + juice[i]);
		//근데 아래와 같이 2번 안먹는 경우도 있으므로
		//이 부분만 어떻게 하면..
		arr[i] = max(arr[i], arr[i - 1]);
	}
	cout << arr[N];
}

/*
   100 400 2 1 4 200
a  O    O  X X O O
my O    O  X O X O

=>즉 2개를 건너뛰는 상황을 cover하지 못하고 있음
=>결국 arr[i]를 채워가는 과정에서 이전 값과 현재 값을 비교해야함
*/