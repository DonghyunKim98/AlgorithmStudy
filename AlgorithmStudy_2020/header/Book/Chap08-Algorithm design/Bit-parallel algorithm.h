#include <bits/stdc++.h>
#include <intrin.h>
using namespace std;
//��Ʈ ���� �˰��� ����
string a, b;
int A, B;
void HammingDistance() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	cout << "0�� 1�� �̷���� ���ڿ� 2���� �Է��ϼ���.\n";
	cin >> a >> b;
	A = stoi(a);
	B = stoi(b);

	//process
	int result = __popcnt(A^B);

	//output
	cout << "�־��� ���ڿ��� �ع� �Ÿ��� " << result << "�Դϴ�";
}

/*
	������) stoi�� �ϸ� 10�������� �ٲ۴�.
			2�������� �ٲ���ϴµ� ��..
*/