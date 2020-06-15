#include <bits/stdc++.h>
//2751¹ø ¹®Á¦
using namespace std;

void Sort() {
	int N;
	cin >> N;
	vector<int> vc;

	while (N--) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}

	sort(vc.begin(), vc.end());

	for (auto u : vc) {
		cout << u << '\n';
	}
}