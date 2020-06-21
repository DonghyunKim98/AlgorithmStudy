#include <bits/stdc++.h>
//14888번 문제
using namespace std;
int N;
long long ans_max = -1 * LONG_MAX, ans_min = LONG_MAX;
vector<int> number;
vector<char> operation;
void DFS(int cnt, int plus_cnt, int minus_cnt, int multiple_cnt, int division_cnt) {
	//연산자가 N-1개 있다
	if (cnt == N - 1) {
		long long result = number.at(0);
		//1+2+3+4+5
		//0 1 2 3 4 -> number index
		// 0 1 2 3  -> operation index
		for (int i = 0; i < number.size() - 1; i++) {
			if (operation.at(i) == '+') result += number.at(i + 1);

			else if (operation.at(i) == '-') result -= number.at(i + 1);
			else if (operation.at(i) == '*') result *= number.at(i + 1);
			else result /= number.at(i + 1);
		}
		ans_max = max(result, ans_max);
		ans_min = min(result, ans_min);
	}
	else {
		//'+'->'-'->'*'->'/' 순으로 차근차근 넣는다.
		if (plus_cnt > 0) {
			operation.push_back('+');
			plus_cnt--;
			DFS(cnt + 1, plus_cnt, minus_cnt, multiple_cnt, division_cnt);
			//BackTracking
			operation.pop_back();
			plus_cnt++;
		}
		if (minus_cnt > 0) {
			operation.push_back('-');
			minus_cnt--;
			DFS(cnt + 1, plus_cnt, minus_cnt, multiple_cnt, division_cnt);
			operation.pop_back();
			minus_cnt++;
		}
		if (multiple_cnt > 0) {
			operation.push_back('*');
			multiple_cnt--;
			DFS(cnt + 1, plus_cnt, minus_cnt, multiple_cnt, division_cnt);
			operation.pop_back();
			multiple_cnt++;
		}
		if (division_cnt > 0) {
			operation.push_back('/');
			division_cnt--;
			DFS(cnt + 1, plus_cnt, minus_cnt, multiple_cnt, division_cnt);
			operation.pop_back();
			division_cnt++;
		}
	}
}

// 1+2+3 -> N=3
// 01234

void OperatorInput() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	int plus, minus, multiple, division;
	cin >> plus >> minus >> multiple >> division;
	DFS(0, plus, minus, multiple, division);

	cout << ans_max << '\n' << ans_min;
}