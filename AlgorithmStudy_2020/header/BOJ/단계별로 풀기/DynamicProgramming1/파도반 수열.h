#include <bits/stdc++.h>
//9461�� ����
using namespace std;
long long arr[101];
void Wave() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	//base case
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	//Dynamic Programming 
	for (int i = 6; i <= 100; i++)
		arr[i] = arr[i - 1] + arr[i - 5];
	while (T > 0) {
		int N;
		cin >> N;
		cout << arr[N]<<'\n';
		T--;
	}

}

/*
 	k	P(k)
	1    1 
	2    1
	3    1
	4    1+1(2)
	5    2
	6    1+2(3)
	7    1+3(4)
	8    1+4(5)
	9    2+5(7)
	10   2+7(9)
	11   3+9(12)
	12   4+12(16)
	13   5+16(21)
	�Ķ����� ����� ����� �Ķ����� ������ ����
	��ȭ�� : an = a(n-1) + a(n-5)

	//�˰���
	-> �ݺ����� �̿��ؼ� ������ ���̹Ƿ�, �̸� 100���� �� ��������
*/