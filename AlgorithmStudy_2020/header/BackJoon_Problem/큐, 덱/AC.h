#include <bits/stdc++.h>
//5430�� ����
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
			//�Լ��� �� ������ ���!
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

			//�տ��� ����!
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
			//�ڿ��� ����!
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
	�����⿡ ���� ����
	=> �⺻���� �տ��� ����
	=> R�� ������ �������� �ڿ�������!
	=>
*/