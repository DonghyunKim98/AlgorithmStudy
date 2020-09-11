#include <bits/stdc++.h>
//2529번 문제
using namespace std;
int K;
bool is_big[9];
bool num_used[10] = { false, };
string min_num = "999999999999", max_num = "0";
void DFS(int digit,string temp_ret) {
	//부등호가 K개 => 자리수는 K+1개.
	//그러므로 K+2 digit일때 검사해야함
	if (digit == K + 2) {
		min_num = min(min_num, temp_ret);
		max_num = max(max_num, temp_ret);
		return;
	}
	if (digit == 1) {
		for (int i = 0; i <= 9; i++) {
			temp_ret+=to_string(i);
			num_used[i] = true;
			DFS(digit + 1, temp_ret);
			temp_ret.pop_back();
			num_used[i] = false;
		}
	}
	else {
		//이번 자릿수가 더 커야하면 true, 더 작아야하면 false
		bool should_be_big = is_big[digit-2];
		for (int i = 0; i <= 9; i++) {
			//이미 쓰인 숫자라면 pass
			if (num_used[i]) continue;
			//더 커야 하는데
			if (should_be_big) {
				//안 크면
				if ((int)(temp_ret.back()-'0') > i) continue;
			}
			//더 작아야 하는데
			else {
				//안 작으면
				if ((int)(temp_ret.back()-'0') < i) continue;
			}
			temp_ret+=to_string(i);
			num_used[i] = true;
			DFS(digit + 1, temp_ret);
			temp_ret.pop_back();
			num_used[i] = false;
		}
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K;
	for (int i = 0; i < K; i++) {
		char temp;
		cin >> temp;
		temp == '<' ? is_big[i] = true : is_big[i] = false;
	}

	DFS(1,"");
	cout << max_num << '\n' << min_num;
}

/*
	문자열 관련 함수들이 좀 어렵다
	to_string, (int) conversion 등등이
	헷갈리지말고 잘 정리해서 써야할 것 같다.
*/