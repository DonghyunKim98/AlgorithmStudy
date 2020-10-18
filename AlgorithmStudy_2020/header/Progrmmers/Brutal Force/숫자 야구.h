#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> baseball) {
	int answer = 0;

	//��� ���� ����
	for (int number = 123; number <= 987; number++) {
		int digit[3];
		digit[0] = number / 100, digit[1] = (number % 100) / 10, digit[2] = number % 10;
		//���ڰ� ������ �� ��
		if (digit[0] == digit[1] || digit[1] == digit[2] || digit[0] == digit[2]) continue;
		//0�� �����ϸ� �� ��
		if (digit[1] == 0 || digit[2] == 0) continue;
		bool is_right = true;
		//strike ball ���� Ȯ��
		for (int i = 0; i < baseball.size(); i++) {
			int temp = baseball[i][0];
			int strike = 0, ball = 0;
			//strike Ȯ��
			if (temp / 100 == digit[0]) strike++;
			if ((temp % 100) / 10 == digit[1]) strike++;
			if (temp % 10 == digit[2]) strike++;
			if (strike != baseball[i][1]) {
				is_right = false;
				continue;
			}
			//ballȮ��
			if (temp / 100 == digit[1] || temp / 100 == digit[2]) ball++;
			if ((temp % 100) / 10 == digit[0] || (temp % 100) / 10 == digit[2])ball++;
			if (temp % 10 == digit[0] || temp % 10 == digit[1])ball++;
			if (ball != baseball[i][2]) {
				is_right = false;
				continue;
			}
		}
		if (is_right) answer++;
	}

	return answer;
}

/*
	�˰��� ����Ʈ
	=> �Ҽ� ã��� �����ϴ�
	=> "�־��� ��Ʈ����ũ�� ��"�� ���ڸ� �߷�x
	=> ���� ���� ���ڰ� �־��� ��Ʈ����ũ�� ���� �´��� check O

	*�ϸ鼭 ������ �ǵ�, ��ǻ������ �ſ� �ٻ��� �˰���, �����ɷº��ٴ� �׳� �����ڴ°͵� �������� �ִ�.
*/