/*#include <iostream>

using namespace std;

int main() {
	int number_in_decimal;
	cout << "2�������� ��Ÿ���� ���� ���ڸ� �ϳ� �Է��ϼ���: ";
	cin >> number_in_decimal;
	
	cout << "2�������� ��Ÿ���� ";
	for (int k = 31; k >= 0; k--) {
		if (number_in_decimal & (1 << k)) cout << "1";
		else cout << "0";
	}
	cout << " �Դϴ�.";

}
*/
/*
	 Algorithm Point : Bitmask�� ���� ���� ������ ����. Bit operation ���� �ƴ϶�� ����������
					   ��� ���� ���� ���ٴ� �� �˾Ҵ�. ���� ���ؼ� �� �����. ��� ����صΰ�.
					   ���� ���߿����� ���� ����� �� ���� �� ����.
*/