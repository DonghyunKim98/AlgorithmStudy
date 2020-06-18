#include <bits/stdc++.h>
//1541번 문제
//https://sihyungyou.github.io/baekjoon-1541/ 참고
using namespace std;

void MissingParenthesis() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char* str = new char[51];
	int arr[25] = { 0, };
	cin >> str;
	int i = 0, j = 0;
	int temp = 0, sum = 0;
	bool is_minus_front = false;
	string temp_number = "";
	while (str[i] != '\0') {
		if (str[i] == '+') {
			sum += temp;
			temp = 0;
		}
		else if (str[i] == '-') {
			sum += temp;
			arr[j] = sum;
			j++;
			temp = 0;
			sum = 0;
		}
		else {
			temp *= 10;
			temp += (str[i] - '0');
		}
		i++;
	}
	sum += temp;
	arr[j] = sum;

	int ans = arr[0];
	for (int i = 1; i < 25; i++) {
		ans -= arr[i];
	}
	cout << ans;
}

/* 
	마이너스 만날때마다 괄호로 묶어주자 ->문자열을 처리하는 도중에 하지말고 부분합을 배열에 저장하고 마지막에 한번에 처리. (맨 처음부터 -가 나오지는 않는다고했으니깐)
	문자열 관련이 진짜 약하다. 아스키문자...!!
*/