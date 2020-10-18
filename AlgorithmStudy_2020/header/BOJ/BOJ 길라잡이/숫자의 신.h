#include <bits/stdc++.h>
//1422�� ����
using namespace std;
int K, N;
vector<string> vc;

bool cmp(string a, string b) {
	if (a == b) return a < b;
	if (a + b == b + a) return a.length() > b.length();
	else return a + b > b + a;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K >> N;
	int max_num = 0;
	for (int i = 0; i < K; i++) {
		string temp;
		cin >> temp;
		vc.push_back(temp);
		max_num = max(max_num, stoi(temp));
	}
	sort(vc.begin(), vc.end(), cmp);
	string answer;
	bool is_max_used = false;
	for (int i = 0; i < K; i++) {
		if (stoi(vc[i]) == max_num&& !is_max_used) {
			for (int j = 0; j < N - K + 1; j++) {
				answer += vc[i];
			}
			is_max_used = true;
			continue;
		}
		answer += vc[i];
	}
	cout << answer;
}


/*
	<1�ܰ� ����>
		1. �ϴ� ���ʺ��� �������� ���ذ��鼭, ���ڰ� ū ���� �տ� ������ �Ѵ�
		2. ���� �Ϻ��� �ڸ����� ���ٸ�, �ٽ� ó������ ���ư��� ���Ѵ�.
		ex) 7747 vs 774785 ���� ��� 4�ڸ� ����, 7747�� �ٽ� 0��° idx�� ���ؼ�
			7�� 8�� ���Ѵ�.
		3. ���� �Ϻ��� ���� ���ڶ�� �׳� �ƹ��ų� ���� �͵� �������. -> ���ϸ��� �б���
		=> ������: �ڸ����� �� Ŀ����, �װ� �� ���� ���°� �̵��̴�.
		   ex) 47 9 �� �ְ� 3�� ���� �ϸ�
			   9947 ���� 94747�� �̵���.
	<2�ܰ� ����>
		1. <1�ܰ� ����>���� �з��Ѵ�� �;� �ϴ� ���� ����
		   �ٸ� � ���ڰ� ���� ���� �ݺ��Ǿ� �ϴ°�?
				=> �ڸ����� ���� ū ���߿� ���� �������� ��!
				=> �̸� �Է´ܰ迡�� �����ؾ��� �� ����.

	<3�ܰ� ����>
		1. �κ������� �ݺ��Ǵ� ���� cmp���� infinite loop�� ����
			ex) 123 �� 123123


	<4�ܰ� ����>
		1.�ᱹ �ٽ� ���� ���Ƽ� ������ ����� �̷������ �ʰ� ��� ���ܰ� �߻��ؼ�
		  a+b�� b+a�� �� ū������ �����ϸ� �ȴ�. =>�ٽ�!
		2.���� 2���� ���ٸ�, �� �ڸ����� ū ���� ������ ���� �ȴ�.
*/
