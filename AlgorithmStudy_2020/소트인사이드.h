#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SortInside() {
	int num;
	cin >> num;
	vector <int> vc;
	while (num > 0) {
		int temp = num % 10;
		vc.push_back(temp);
		num /= 10;
	}
	sort(vc.rbegin(),vc.rend());

	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i];
	}

	return;
}
