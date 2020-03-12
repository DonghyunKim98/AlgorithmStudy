#include <iostream>
#include <vector>
#include <intrin.h>

using namespace std;

int main() {
	// 집합은 무조건 {0,1,2,...n-1} 임을 가정
	int n;
	cout << "집합의 원소의 개수를 입력하세요: ";
	cin >> n;
	cout << "----모든 부분집합----" << endl;
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
	cout << "부분집합의 원소의 개수를 입력하세요: ";
	cin >> k;
	cout << "-----원소의 개수가 " << k << "인 부분집합 ------" << endl;
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
		//원소의 개수를 모른다고 가정
		/*
		int x = n;
		b = 0;
		do {
			int temp = b;
			//n의 크기를 모르니깐 31로 설정할수 밖에 없나..?
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