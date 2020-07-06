#include <bits/stdc++.h>
//11650¹ø ¹®Á¦
using namespace std;

bool compare(pair<int,int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

void location() {
	int N;
	cin >> N;
	vector<pair<int, int>> vc;
	for (int i = 0; i < N; i++) {
		int xpos, ypos;
		cin >> xpos >> ypos;
		vc.push_back(make_pair(xpos, ypos));
	}
	sort(vc.begin(), vc.end(), compare);

	for (int i = 0; i < N; i++)
		cout << vc.at(i).first << ' ' << vc.at(i).second << '\n';
}