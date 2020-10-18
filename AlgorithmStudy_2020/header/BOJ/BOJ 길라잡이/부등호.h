#include <bits/stdc++.h>
//2529�� ����
using namespace std;
int K;
bool is_big[9];
bool num_used[10] = { false, };
string min_num = "999999999999", max_num = "0";
void DFS(int digit,string temp_ret) {
	//�ε�ȣ�� K�� => �ڸ����� K+1��.
	//�׷��Ƿ� K+2 digit�϶� �˻��ؾ���
	if (digit == K + 2) {
		min_num = min(min_num, temp_ret);
		max_num = max(max_num, temp_ret);
		return;
	}
	if (digit == 1) {
		for (int i = 0; i <= 9; i++) {
			temp_ret+=to_string(i);
			num_used[i] = true;
			DFS(digit + 1, temp_ret);
			temp_ret.pop_back();
			num_used[i] = false;
		}
	}
	else {
		//�̹� �ڸ����� �� Ŀ���ϸ� true, �� �۾ƾ��ϸ� false
		bool should_be_big = is_big[digit-2];
		for (int i = 0; i <= 9; i++) {
			//�̹� ���� ���ڶ�� pass
			if (num_used[i]) continue;
			//�� Ŀ�� �ϴµ�
			if (should_be_big) {
				//�� ũ��
				if ((int)(temp_ret.back()-'0') > i) continue;
			}
			//�� �۾ƾ� �ϴµ�
			else {
				//�� ������
				if ((int)(temp_ret.back()-'0') < i) continue;
			}
			temp_ret+=to_string(i);
			num_used[i] = true;
			DFS(digit + 1, temp_ret);
			temp_ret.pop_back();
			num_used[i] = false;
		}
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K;
	for (int i = 0; i < K; i++) {
		char temp;
		cin >> temp;
		temp == '<' ? is_big[i] = true : is_big[i] = false;
	}

	DFS(1,"");
	cout << max_num << '\n' << min_num;
}

/*
	���ڿ� ���� �Լ����� �� ��ƴ�
	to_string, (int) conversion �����
	�򰥸������� �� �����ؼ� ����� �� ����.
*/