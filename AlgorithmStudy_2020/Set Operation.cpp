#include <iostream>
#include <vector>
#include <intrin.h>

using namespace std;

int main() {
	// ������ ������ {0,1,2,...n-1} ���� ����
	int n;
	cout << "������ ������ ������ �Է��ϼ���: ";
	cin >> n;
	cout << "----��� �κ�����----" << endl;
	for (int b = 0; b < (1 << n); b++) {
		cout << "{";
		int count = __popcnt(b) - 1;
		for (int j = n - 1; j >= 0; j--) {
			if (count == 0) {
				if (b & (1 << j)) {
					cout << j;
					count--;
				}
			}
			else {
				if (b & (1 << j)) {
					cout << j << ',';
					count--;
				}
			}
		}
		cout << "}\n";
	}
	int k;
	cout << "�κ������� ������ ������ �Է��ϼ���: ";
	cin >> k;
	cout << "-----������ ������ " << k << "�� �κ����� ------" << endl;
	for (int b = 0; b < (1 << n); b++) {
		if (__popcnt(b) == k) {
			cout << __popcnt(b) << endl;
			for (int j = 0; j < (1 << n); j++) {
				cout << "{";
				int count = __popcnt(b) - 1;
				{
					if (count == 0) {
						if (b & (1 << j)) {
							cout << j;
							count--;
						}
					}
					else {
						if (b & (1 << j)) {
							cout << j << ',';
							count--;
						}
					}
				}
				cout << "}\n";
			}
		}
		//������ ������ �𸥴ٰ� ����
		/*
		int x = n;
		b = 0;
		do {
			int temp = b;
			//n�� ũ�⸦ �𸣴ϱ� 31�� �����Ҽ� �ۿ� ����..?
			for (int b = 0; b < (1 << 4); b++) {
				cout << "{";
				int count = __popcnt(b) - 1;
				for (int j = n - 1; j >= 0; j--) {
					if (count == 0) {
						if (b & (1 << j)) {
							cout << j;
							count--;
						}
					}
					else {
						if (b & (1 << j)) {
							cout << j << ',';
							count--;
						}
					}
				}
				cout << "}\n";
			}
			b = temp;
			b++;
		} while (b = (b - x) & x);
		*/
	}
}