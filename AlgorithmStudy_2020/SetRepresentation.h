#include <iostream>
#include <vector>
#include <intrin.h>
using namespace std;

int Subset() {
	int n = 0;
	int x = 0;
	char temp;
	vector<int> vc;
	cout << "���տ� ���Ե� ���Ҹ� �Է��ϼ��� (0~31), �ϳ��� �Է������� �����̽��ٸ� ������ �� �Է������� ���͸� �������� :";
	while (cin >> temp) {
		if (temp == '\n') break;
		else if (temp == ' ') continue;
		else {
			vc.push_back(int(temp));
		}
	}

	for (int i = 0; i < vc.size(); i++) {
		x |= (1 << vc[i]);
	}
	cout << "������ ����: " << __popcnt(x) << endl; // GNU �����Ϸ����� __builtin_popcount()��!
	cout << "���տ� ���Ե� ��� ���Ҵ� ";
	for (int i = 0; i < 32; i++) {
		if (x & (1 << i)) cout << i << " ";
	}
}
