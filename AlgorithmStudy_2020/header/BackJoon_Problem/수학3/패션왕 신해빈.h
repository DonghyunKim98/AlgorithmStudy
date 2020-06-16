#include <bits/stdc++.h>
//9375¹ø ¹®Á¦
using namespace std;

void Fashion() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int N;
		cin >> N;
		vector <pair<string, int>> vc;

		for (int i = 0; i < N; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			int size = vc.size();
			for (int i = 0; i <= size; i++) {
				if (i == size) vc.push_back(make_pair(s2, 1));
				else if (vc.at(i).first == s2) {
					vc.at(i).second++;
					break;
				}
			}
		}

		int ans = 1;
		for (auto u : vc)
			ans *= (u.second+1);
		cout << ans - 1 << '\n';
		T--;
	}
}