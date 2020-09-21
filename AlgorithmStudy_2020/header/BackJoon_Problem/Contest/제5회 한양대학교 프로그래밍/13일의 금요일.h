#include <bits/stdc++.h>
//16463번 문제
using namespace std;
int N;
int ans = 0;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//[일요일,토요일]->[0,6]
	//2018년 12월 13일은 목요일
	int day = 4;
	for (int year = 2019; year <= N; year++) {
		for (int month = 1; month <= 12; month++) {
			//직전달이 31일
			if (month == 1 || month==2 ||month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
				day = (day + 3) % 7;
			}
			//직전달이 30일
			else if (month == 5 || month == 7 || month == 10 || month == 12) {
				day = (day + 2) % 7;
			}
			//직전달이 2월
			else {
				//4의배수
				if (year % 4 == 0) {
					//100의 배수
					if (year % 100 == 0) {
						//400의 배수 -> 윤년
						if (year % 400 == 0) {
							day = (day + 1) % 7;
						}
						//100의 배수이지만 400의 배수가 아님 -> 윤년이 아님
					}
					//4이배수이지만 100의 배수가 아님 -> 윤년
					else day = (day + 1) % 7;
				}
			}
			if (day == 5) {
				ans++;
			}
		}
	}
	std::cout << ans;
}