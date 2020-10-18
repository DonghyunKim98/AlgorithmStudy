#include <bits/stdc++.h>
//2661번 문제
using namespace std;
typedef long long ll;
int N;

void DFS(int cnt, string temp_ret) {
	//유능한지 검사.
	//첫번째 for문 -> 검사할 수열의 시작 위치
	for (int i = 0; i < temp_ret.length(); i++) {
		int j = 0;
		//두번째 while문 -> 검사할 수열의 사이즈
		while(++j){
			if (i + (j * 2)-1 > temp_ret.length() - 1) break;
			//세번째 for문 -> 현재 검사하고 있는 idx
			for (int k = 0; k < j; k++) {
				if (temp_ret[i + k] != temp_ret[i + j + k]) break;
				if (k == j - 1) return;
			}
		}
	}

	if (cnt == N) {
		//어차피 최초로 도착한 순간일 것이므로 바로 출력
		cout << temp_ret;
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		temp_ret+=to_string(i);
		DFS(cnt + 1, temp_ret);
		temp_ret.pop_back();
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	DFS(0,"");
}

/*
	1. 단순 3^80으로는 당연히 시간초과. BackTracking idea가 필요했다.
	2. for문 3개를 중첩하는 과정이 어려웠다. 
	처음엔 
	[수열의 길이 -> 수열의 시작 위치 -> ...] 
	순으로 짰는데 어렵다는 걸 알고 
	[수열의 시작 위치 -> 수열의 길이 -> 비교할 idx]
	로 짰더니 편했다
	3. 특이하게 N일때 출력을 해야하므로, 유능한지 검사하고 cnt가 N인지를 바로 검사해야 했다.


	* 다른 사람 풀이들을 보니, substr을 쓰는 곳도 많다. 자주 사용하도록 하자.
*/