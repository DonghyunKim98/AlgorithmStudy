#include <bits/stdc++.h>
//16463�� ����
using namespace std;
int N;
int ans = 0;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//[�Ͽ���,�����]->[0,6]
	//2018�� 12�� 13���� �����
	int day = 4;
	for (int year = 2019; year <= N; year++) {
		for (int month = 1; month <= 12; month++) {
			//�������� 31��
			if (month == 1 || month==2 ||month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
				day = (day + 3) % 7;
			}
			//�������� 30��
			else if (month == 5 || month == 7 || month == 10 || month == 12) {
				day = (day + 2) % 7;
			}
			//�������� 2��
			else {
				//4�ǹ��
				if (year % 4 == 0) {
					//100�� ���
					if (year % 100 == 0) {
						//400�� ��� -> ����
						if (year % 400 == 0) {
							day = (day + 1) % 7;
						}
						//100�� ��������� 400�� ����� �ƴ� -> ������ �ƴ�
					}
					//4�̹�������� 100�� ����� �ƴ� -> ����
					else day = (day + 1) % 7;
				}
			}
			if (day == 5) {
				ans++;
			}
		}
	}
	std::cout << ans;
}