#pragma warning(disable: 4996)
#include <bits/stdc++.h>
//16470¹ø ¹®Á¦
using namespace std;

void solution() {
	map<string, int> mp;
	int M = 0;
	for (string line; getline(std::cin, line); ){
		if (line.empty()) { break; }
		mp[line]++;
		M++;
	}
	map<string, int>::iterator it;
	double ans = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		double p = ((double)it->second / M);
		ans += p*p;
	}
	printf("%.8lf", (1 - ans));
}