#include <bits/stdc++.h>
//17950�� ����
using namespace std;
const int m = 1000000007;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h, x;
	cin >> h >> x;

	long long answer = 0;
	long long i = 1;
	while (h > 0) {
		i *= x;
		int temp;
		cin >> temp;
		answer += (temp * i);
		i %= m;
		answer %= m;
		h--;
	}
	cout << answer;
}

/*
	�˰��� ����Ʈ 
	=> 0.5�ʶ�� �� �׸��� �������� �����ؼ� ��� �����̶�� ��
	�� ������ ����� �������� ������ �ʰ� x�� ���ϸ� ���� �������� �̿��� �� �ִٴ� ��
	�̸� �̿��ؾ� �ð��ʰ��� ������ �ʴ´�.

	�׸��� ���� long long ����... ����� Ʋ���� �ų� ���а��� ��������
*/