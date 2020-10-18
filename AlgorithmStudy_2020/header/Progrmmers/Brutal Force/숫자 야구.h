#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> baseball) {
	int answer = 0;

	//모든 숫자 돌기
	for (int number = 123; number <= 987; number++) {
		int digit[3];
		digit[0] = number / 100, digit[1] = (number % 100) / 10, digit[2] = number % 10;
		//숫자가 같으면 안 됨
		if (digit[0] == digit[1] || digit[1] == digit[2] || digit[0] == digit[2]) continue;
		//0을 포함하면 안 됨
		if (digit[1] == 0 || digit[2] == 0) continue;
		bool is_right = true;
		//strike ball 여부 확인
		for (int i = 0; i < baseball.size(); i++) {
			int temp = baseball[i][0];
			int strike = 0, ball = 0;
			//strike 확인
			if (temp / 100 == digit[0]) strike++;
			if ((temp % 100) / 10 == digit[1]) strike++;
			if (temp % 10 == digit[2]) strike++;
			if (strike != baseball[i][1]) {
				is_right = false;
				continue;
			}
			//ball확인
			if (temp / 100 == digit[1] || temp / 100 == digit[2]) ball++;
			if ((temp % 100) / 10 == digit[0] || (temp % 100) / 10 == digit[2])ball++;
			if (temp % 10 == digit[0] || temp % 10 == digit[1])ball++;
			if (ball != baseball[i][2]) {
				is_right = false;
				continue;
			}
		}
		if (is_right) answer++;
	}

	return answer;
}

/*
	알고리즘 포인트
	=> 소수 찾기와 동일하다
	=> "주어진 스트라이크와 볼"로 숫자를 추론x
	=> 내가 만든 숫자가 주어진 스트라이크와 볼이 맞는지 check O

	*하면서 느끼는 건데, 컴퓨터한테 매우 근사한 알고리즘, 구현능력보다는 그냥 때려박는것도 좋을때가 있다.
*/