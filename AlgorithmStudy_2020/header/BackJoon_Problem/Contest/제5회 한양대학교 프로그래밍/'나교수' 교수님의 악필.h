#include <bits/stdc++.h>
//16246¹ø ¹®Á¦
using namespace std;
double ans;
bool cmp(int a,int b) {
	return abs(ans - a) < abs(ans - b);
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int total = 0;
	vector<int> vc;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == '6' || temp[j] == '0') {
				temp[j] = '9';
			}
		}
		if (stoi(temp) > 100) temp = "100";
		total += stoi(temp);
		vc.push_back(stoi(temp));
	}
	ans = total / (double)N;
	
	cout << round(ans);
}