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
		//OXOO 의 경우 와 OXO의 경우를 따져준다.
		arr[i] = max(arr[i - 3] + juice[i - 1] + juice[i], arr[i - 2] + juice[i]);
		//그런데 OXXO의 경우도 있음 -> 이것을 이 코드로 커버 가능??
		/*
			YES!! 
			how?) 예를 들어 arr[3] 의 max값이 arr[2]로 됐다면 3번째 잔은 안 먹은것
			      그리고 arr[6]에서 arr[3]의 값을 참조한다면, 3번째잔 4번째잔 다 안먹게 되는 것.
		*/
		arr[i] = max(arr[i], arr[i - 1]);
	}
	cout << arr[N];
}

/*
   100 400 2 1 4 200
a  O    O  X X O O
arr[3] = 500 (OOX)
arr[4] = 501 (OOXO)
arr[5] = 505 (OOXOO)
*/