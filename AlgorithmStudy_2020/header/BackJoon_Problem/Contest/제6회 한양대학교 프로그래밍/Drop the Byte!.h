#include <bits/stdc++.h>
//17949锅 巩力
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string password;
	cin >> password;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input, temp;
		cin >> input;
		if (input == "char") {
			temp = password.substr(0, 2);
			password = password.substr(2, password.size() - 2);
		}
		else if (input == "int") {
			temp = password.substr(0, 8);
			password = password.substr(8, password.size() - 8);
		}
		//long_long 老锭
		else {
			temp = password.substr(0, 16);
			password = password.substr(16, password.size() - 16);
		}
		int answer = 0;
		for (int j = 0; j < temp.size(); j++) {
			//0~9 贸府
			if (temp[j] >= '0' && temp[j] <= '9')
				answer += pow(16, temp.size() - 1 - j) * (temp[j] - '0');
			//a~f 贸府
			else
				answer += pow(16, temp.size() - 1 - j) * (temp[j] - 'a' + 10);
		}
		cout << answer << ' ';
	}
}

