#include <bits/stdc++.h>
//5430번 문제
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void AC() {
	int T;
	cin >> T;
	while (T > 0) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		
		deque<int> dq;
		char arr[400005];
		scanf("%s", &arr);
		char* temp = strtok(arr, "[,]");
		while (temp) {
			dq.push_back(stoi(temp));
			temp = strtok(NULL, "[,]");
		}

		


		bool is_front_first = true;
		for (int i = 0; i <= s.length(); i++) {
			//함수가 다 끝나면 출력!
			if (i == s.length()) {
				cout << '[';
				int size = dq.size();
				for (int j = 0; j < size; j++) {
					if (is_front_first) {
						cout << dq.front();
						dq.pop_front();
					}
					else {
						cout << dq.back();
						dq.pop_back();
					}
					if (j != size - 1) cout << ',';
				}
				cout << "]\n";
			}

			//앞에서 부터!
			if (is_front_first) {
				if (s[i] == 'D') {
					if (dq.empty()) {
						cout << "error\n";
						break;
					}
					else dq.pop_front();
				}
				else is_front_first = false;
			}
			//뒤에서 부터!
			else {
				if (s[i] == 'D') {
					if (dq.empty()) {
						cout << "error\n";
						break;
					}
					else dq.pop_back();
				}
				else is_front_first = true;
			}
		}
		T--;
	}
}

/*
	뒤집기에 대한 구현
	=> 기본값은 앞에서 부터
	=> R이 들어오면 이제부터 뒤에서부터!
	=>
*/