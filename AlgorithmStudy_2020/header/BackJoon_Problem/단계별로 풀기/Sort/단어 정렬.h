#include <bits/stdc++.h>
//1181¹ø ¹®Á¦
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}

void Word() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<string> vc;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		vc.push_back(temp);
	}

	sort(vc.begin(), vc.end(), compare);
	/*unique(vc.begin(), vc.end());*/

	string temp;
	for (int i = 0; i < N; i++) {
		if (temp == vc.at(i)) continue;
		cout << vc.at(i) << '\n';
		temp = vc.at(i);
	}
}