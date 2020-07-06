#include <bits/stdc++.h>
//1037¹ø ¹®Á¦
using namespace std;

void Measure() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vc;
	int N;
	cin >> N;
	int temp;
	while (N > 0) {
		cin >> temp;
		vc.push_back(temp);
		N--;
	}
	sort(vc.begin(), vc.end());
	cout << vc.at(0) * vc.at(vc.size()-1);
}