#include <bits/stdc++.h>
//1016�� ����
using namespace std;
const int MAX = 1000+1;
typedef long long ll;
bool result[1000001] = { false };
ll num[1000001] = { 0 };


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll sq_max = (ll)sqrt(b);					//���� �� �������� �� �� �ִ� ���� ū ��
	ll cntNum = 0;								//�������� ����
	for (ll i = 2; i <= sq_max; i++) {
		num[i] = i * i;
		cntNum++;
	}
	int cnt = 0;								//���� �� ������ ���� ������ �������� ��
	for (int i = 2; i < cntNum +2; i++) {
		ll div_min = a;							//div_min�� ������ �ּҰ� min���� �� ��
		if (div_min % num[i] != 0)				//div_min�� �������� ������ ���� �ʴ´ٸ�
			div_min = (a / num[i] + 1) * num[i];//�ּҰ��� ���������� ���� �� +1�� �ٽ� ���ؼ� ���� ���� ������ �ٲ�

		for (ll tmp = div_min; tmp <= b; tmp += num[i]) {//num[i]�� ���������� div_min�� count�Ѵ�
			if (!result[tmp - a]) {
				result[tmp - a] = true;
				cnt++;
			}
		}
	}
	cout << b - a + 1 - cnt;
}

/*
	idea 1 
		=> �ð��� 2�ʰ�, "ȯ���� ¦��"���� ��� ����� �ᵵ 1�鸸 X 10�� ���� 1���� �Ѿ
		=> ����, "�־��� ����" �������� �������� ������������ �� �������������� Ȯ��
	idea 2
		=> �������� �� �ִ� �������� �ִ밪�� �־��� ������ �ִ밪�� root ��
	idea 3
		=> �Ҽ��� ã���� ���������� �̿��ؼ� ���������� �͵��� �Ÿ��� ("��ü-�ݷ�" �� �̿�)
*/