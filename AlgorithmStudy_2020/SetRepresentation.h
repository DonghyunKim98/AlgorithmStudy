#include <iostream>
#include <vector>
#include <intrin.h>
using namespace std;

int Subset() {
	int n = 0;
	int x = 0;
	char temp;
	vector<int> vc;
	cout << "집합에 포함될 원소를 입력하세요 (0~31), 하나를 입력했으면 스페이스바를 누르고 다 입력했으면 엔터를 누르세요 :";
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
	cout << "원소의 개수: " << __popcnt(x) << endl; // GNU 컴파일러에선 __builtin_popcount()로!
	cout << "집합에 포함된 모든 원소는 ";
	for (int i = 0; i < 32; i++) {
		if (x & (1 << i)) cout << i << " ";
	}
}
