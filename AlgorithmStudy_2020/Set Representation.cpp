#include <iostream>
#include <vector>
#include <intrin.h>
using namespace std;

int main() {
	int n= 0;
	int x= 0;
	vector<int> vc;
	cout << "집합에 포함될 원소를 입력하세요 (0~31), 다 입력했으면 엔터를 누르세요 :";
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
	cout << "원소의 개수: " << __popcnt(x) << endl; // GNU 컴파일러에선 __builtin_popcount()로!
	cout << "집합에 포함된 모든 원소는 ";
	for (int i = 0; i < 32; i++) {
		if (x & (1 << i)) cout << i << " ";
	}

	cout << "git hub commit test12 " << endl;
}