#include <bits/stdc++.h>
//16464�� ����
using namespace std;
typedef long long ll;
bool check(ll num) {
	while (num > 1) {
		if (num % 2 == 1) return true;
		num /= 2;
	}
	return false;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//��ó��

	int N;
	cin >> N;
	while (N--) {
		ll K;
		cin >> K;
		if (check(K)) cout << "Gazua\n";
		else cout << "GoHanGang\n";
	}
}

/*
	-> Ȧ���� ������ ��
	-> ¦����??
		=>2�� �ŵ������� �ƴϸ� ��
		why?) ¦���� 3�� ��� -> k/3 -1, k/3 , k/3 +1
			  ¦���� 5�� ��� -> k/5 -2 , k/5 -1, k/5, k/5 +1, k/5 +2 ...
			  => �̷����� �Ǿ� 2�� �ŵ������� �����ϰ� ���� �ǰ� �Ǿ�����
*/