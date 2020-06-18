#include <bits/stdc++.h>
//1541�� ����
//https://sihyungyou.github.io/baekjoon-1541/ ����
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
	���̳ʽ� ���������� ��ȣ�� �������� ->���ڿ��� ó���ϴ� ���߿� �������� �κ����� �迭�� �����ϰ� �������� �ѹ��� ó��. (�� ó������ -�� �������� �ʴ´ٰ������ϱ�)
	���ڿ� ������ ��¥ ���ϴ�. �ƽ�Ű����...!!
*/