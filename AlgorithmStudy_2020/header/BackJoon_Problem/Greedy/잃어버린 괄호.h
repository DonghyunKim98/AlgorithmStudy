#include <bits/stdc++.h>
//1541번 문제
using namespace std;

void MissingParenthesis() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char* str= new char[50];
	cin >> str;
	int i = 0;
	int temp_value=0, value=0;
	bool is_minus_front = false;
	string temp_number="";
	while (str[i] != '\0') {
		if (str[i] == '+') {

		}
		else if (str[i] == '-') {
			//앞에서 - 이미 등장한 경우 => 지금까지 연산한 값을 빼줌
			if (is_minus_front) {
				is_minus_front = false;
				value -= temp_value;
				temp_value = 0;
			}
			//안 등장한 경우 => is_minus_front만 true값으로 바꾸어주고 지금부터 연산 진행.
			else {
				is_minus_front = true;
			}
		}
		else 
			temp_number += str[i];

		i++;
	}
	cout << value;
}