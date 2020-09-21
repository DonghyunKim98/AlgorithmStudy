#include <bits/stdc++.h>
//16459¹ø ¹®Á¦
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<string> vc;
	while (true) {
		string temp;
		getline(cin, temp);
		if (temp == "0") break;
		vc.push_back(temp);
	}
	string WHO, WHERE, WHAT;
	getline(cin, WHO);
	getline(cin, WHERE);
	getline(cin, WHAT);
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i].find("WHAT") != -1) {
			vc[i].replace(vc[i].find("WHAT"), 4, WHAT);
		}
		if (vc[i].find("WHERE") != -1) {
			vc[i].replace(vc[i].find("WHERE"), 5, WHERE);
		}
		if (vc[i].find("WHO") != -1) {
			vc[i].replace(vc[i].find("WHO"), 3, WHO);
		}
		cout << vc[i] << '\n';
	}
}