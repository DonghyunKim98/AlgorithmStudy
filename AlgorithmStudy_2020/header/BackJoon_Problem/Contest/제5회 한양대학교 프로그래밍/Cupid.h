#include <bits/stdc++.h>
//16460¹ø ¹®Á¦
using namespace std;
typedef pair<string, pair<string, int>> pssi;
pssi target;
vector<pssi> vc;
vector<string> answer;
int N;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string temp, temp2;
	int temp3;
	cin >> temp >> temp2 >> temp3;
	target = { temp,{temp2,temp3} };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp >> temp2 >> temp3;
		vc.push_back({ temp,{temp2,temp3} });
	}
	for (int i = 0; i < N; i++) {
		if (vc[i].second.second <= target.second.second) {
			if (target.second.first == "F") {
				if (vc[i].second.first == "F") answer.push_back(vc[i].first);
			}
			else if (target.second.first == "M") {
				if(vc[i].second.first=="M")	answer.push_back(vc[i].first);
			}
			else {
				answer.push_back(vc[i].first);
			}
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.empty()) cout << "No one yet\n";
	else for (auto u : answer) cout << u << '\n';
}