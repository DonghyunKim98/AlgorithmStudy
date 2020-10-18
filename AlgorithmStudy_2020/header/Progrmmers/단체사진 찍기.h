#include <string>
#include <vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
vector<bool> flag(1000000000, true);
void check(vector<char> temp, char a, char b, char con, char length, int cnt) {
	int x = 0, y = 0;
	int len = length - '0';
	for (int i = 0; i < 8; i++) {
		if (a == temp[i]) x = i;
		else if (b == temp[i]) y = i;
	}
	if (con == '>') {
		if ((abs(x - y) <= len + 1)) {
			flag[cnt] = false;
		}
	}
	else if (con == '<') {//���ݺ��� �۾ƾ���
		if ((abs(x - y) >= len + 1)) flag[cnt] = false;
	}
	else if (con == '=') {
		if (abs(x - y) != len + 1) {
			flag[cnt] = false;
		}
	}
}
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
	vector<char> friends;
	friends.push_back('A');
	friends.push_back('C');
	friends.push_back('F');
	friends.push_back('J');
	friends.push_back('M');
	friends.push_back('N');
	friends.push_back('R');
	friends.push_back('T');
	int answer = 0;
	vector<char> temp;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		do {
			for (int j = 0; j < 8; j++) {
				temp.push_back(friends[j]);
			}
			if (flag[cnt]) {
				//flag[cnt] �� true �� ��츸 check ����!
				check(temp, data[i][0], data[i][2], data[i][3], data[i][4], cnt);
			}
			//temp vector �ʱ�ȭ
			temp.clear();
			cnt++;
		} while (next_permutation(friends.begin(), friends.end())); 
	}
	for (int i = 0; i < 40320; i++) {
		//8!= 40320
		if (flag[i] == true) {
			//���� 2���� ��� �´°�쿡�� answer++
			answer++;
		}
	}
	return answer;
}