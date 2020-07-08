#include <bits/stdc++.h>
using namespace std;

int get_basic_number(int N, int cnt) {
	int res = 0;
	while (cnt > 0) {
		cnt --;
		res += N * pow(10, cnt);
	}
	return res;
}

int solution(int N, int number) {
	int answer = -1;
	const int MIN = 8;
	vector<set<int>> s(MIN);
	int idx = 1;
	for (int i = 0; i < s.size(); i++) {
		s[i].insert(get_basic_number(N, idx));
		idx ++;
	}
	for (int i = 1; i < MIN; i++) {
		for (int j = 0; j < i; j++) {
			//s[i] = s[j] + s[i-j-1] �� �� (s[i] ��ü�� N �� i-1�� ���ΰ��̱� ����)
			for (const auto& op1 : s[j]) {
				for (const auto& op2 : s[i - j - 1]) {
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if (op2 != 0)
						s[i].insert(op1 / op2);
				}
			}
		}
		if (s[i].find(number) != s[i].end()) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

/*
	�˰��� ����Ʈ
	=> �⺻���� DP ���ε�(an-1���ٰ� number�� ���ϰ� ���� ���ϰ� ������, ������ 0�� �ƴϿ��� �Ѵ�) �� ���÷ȴ�.
	=> ������ ()�� ���� ��Ģ������ �켱���� ������ 5,55,555������ ���ڰ� �پ��ִ� ��쿴�µ�
	=> ���ڰ� �پ��ִ°��� set�� �̿��ؼ� �ذ�. -> ���� �����ؼ� vector�ȿ� vector�� ���� ����
	=> �켱���� ������? 
	ex) 5�� 4������ ����? - 5�� 1�� +-X/ 5�� 3��
						   5�� 2�� +-X/ 5�� 2��
						   5�� 3�� +-X/ 5�� 1��
						   ���� ����ϸ� ��. �̶� �ߺ��� ���� ���� �ʱ� ���� set�� ���°��̱⵵ �ϰ�.

*/