#include <bits/stdc++.h>
//1541�� ����
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
			//�տ��� - �̹� ������ ��� => ���ݱ��� ������ ���� ����
			if (is_minus_front) {
				is_minus_front = false;
				value -= temp_value;
				temp_value = 0;
			}
			//�� ������ ��� => is_minus_front�� true������ �ٲپ��ְ� ���ݺ��� ���� ����.
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