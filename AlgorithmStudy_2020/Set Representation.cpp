#include <iostream>
#include <vector>
#include <intrin.h>
using namespace std;

int main() {
	int n= 0;
	int x= 0;
	vector<int> vc;
	cout << "���տ� ���Ե� ���Ҹ� �Է��ϼ��� (0~31), �� �Է������� ���͸� �������� :";
	do {
		if (cin.get() == '\n') break;
		else {
			vc.push_back(cin.get());
			n++;
		}
	} while (1);

	for (int i = 0; i< n; i++) {
		x |= (1 << vc[i]);
	}
	cout << "������ ����: " << __popcnt(x) << endl; // GNU �����Ϸ����� __builtin_popcount()��!
	cout << "���տ� ���Ե� ��� ���Ҵ� ";
	for (int i = 0; i < 32; i++) {
		if (x & (1 << i)) cout << i << " ";
	}

	cout << "git hub commit test12 " << endl;
}