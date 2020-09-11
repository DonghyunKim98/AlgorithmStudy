#include <bits/stdc++.h>
//1422�� ����
using namespace std;
int K, N;
vector<string> vc;

bool cmp(string a, string b) {
	if (a == b) return a < b;
	//substr���� Ȯ��
	if (a.length() > b.length()) {
		if (a.substr(0,b.length()) == b) return a.length() > b.length();
	}
	else if (a.length() < b.length()) {
		if (b.substr(0,a.length()) == a) return a.length() > b.length();
	}

	int a_idx = 0, b_idx = 0;
	while (true) {
		if (a_idx == a.length()) a_idx = 0;
		if (b_idx == b.length()) b_idx = 0;
		if (a[a_idx] == b[b_idx]) {
			a_idx++; b_idx++;
		}
		else {
			return a[a_idx] > b[b_idx];
		}
	}

}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K >> N;
	int longest_size = 0;
	for (int i = 0; i < K; i++) {
		string temp;
		cin >> temp;
		vc.push_back(temp);
		longest_size = max(longest_size, (int)temp.size());
	}
	sort(vc.begin(), vc.end(), cmp);
	string answer;
	bool long_and_max = false;
	for (int i = 0; i < K; i++) {
		if (vc[i].length() == longest_size) {
			if (!long_and_max) {
				for (int j = 0; j < N - K + 1; j++) {
					answer += vc[i];
				}
				long_and_max = true;
				continue;
			}
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

*/
