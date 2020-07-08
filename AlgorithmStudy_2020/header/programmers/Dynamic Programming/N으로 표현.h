#include <bits/stdc++.h>
using namespace std;

int get_basic_number(int N, int cnt) {
	int res = 0;
	while (cnt > 0) {
		cnt --;
		res += N * pow(10, cnt);
	}
	return res;
}

int solution(int N, int number) {
	int answer = -1;
	const int MIN = 8;
	vector<set<int>> s(MIN);
	int idx = 1;
	for (int i = 0; i < s.size(); i++) {
		s[i].insert(get_basic_number(N, idx));
		idx ++;
	}
	for (int i = 1; i < MIN; i++) {
		for (int j = 0; j < i; j++) {
			//s[i] = s[j] + s[i-j-1] 이 됨 (s[i] 자체가 N 이 i-1번 쓰인것이기 때문)
			for (const auto& op1 : s[j]) {
				for (const auto& op2 : s[i - j - 1]) {
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if (op2 != 0)
						s[i].insert(op1 / op2);
				}
			}
		}
		if (s[i].find(number) != s[i].end()) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

/*
	알고리즘 포인트
	=> 기본적인 DP 마인드(an-1에다가 number를 더하고 빼고 곱하고 나누고, 나눌땐 0이 아니여야 한다) 는 떠올렸다.
	=> 문제는 ()로 인한 사칙연산의 우선순위 문제와 5,55,555등으로 숫자가 붙어있는 경우였는데
	=> 숫자가 붙어있는것은 set을 이용해서 해결. -> 쉽게 생각해서 vector안에 vector를 만들어서 보관
	=> 우선순위 문제는? 
	ex) 5가 4번쓰인 것은? - 5가 1번 +-X/ 5가 3번
						   5가 2번 +-X/ 5가 2번
						   5가 3번 +-X/ 5가 1번
						   으로 계산하면 됨. 이때 중복된 것을 넣지 않기 위해 set을 쓰는것이기도 하고.

*/