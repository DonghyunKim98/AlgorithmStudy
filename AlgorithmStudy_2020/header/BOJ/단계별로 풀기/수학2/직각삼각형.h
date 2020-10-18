#include <bits/stdc++.h>
//4153¹ø ¹®Á¦
using namespace std;

void Right_Triangle() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		int A, B, C;
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0) break;

		vector<int> vc;
		vc.push_back(A);
		vc.push_back(B);
		vc.push_back(C);
		sort(vc.begin(), vc.end());

		if (pow(vc.at(0), 2) + pow(vc.at(1), 2) == pow(vc.at(2), 2)) cout << "right\n";
		else cout << "wrong\n";
	}

}