#include <bits/stdc++.h>
//17949�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string password;
	cin >> password;

	int N;
	cin >> N;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		string input, temp;
		cin >> input;
		int cnt;
		if (input == "char") cnt = 2;
		else if (input == "int") cnt = 8;
		//long_long �϶�
		else cnt = 16;
		long long answer = 0;
		for (int j = 0; j < cnt; j++) {
			//0~9 ó��
			if (password[idx + j] >= '0' && password[idx + j] <= '9')
				answer = answer*16 + (password[idx + j] - '0');
			//a~f ó��
			else
				answer = answer*16 + (password[idx + j] - 'a' + 10);
		}
		cout << answer << ' ';

		if (input == "char") idx += 2;
		else if (input == "int") idx += 8;
		//long_long �϶�
		else idx += 16;
	}
}

