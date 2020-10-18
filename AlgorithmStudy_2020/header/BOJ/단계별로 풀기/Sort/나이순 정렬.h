#include <bits/stdc++.h>
//10814번
using namespace std;

bool compare(pair<int,string> a, pair<int,string>b) {
	return a.first < b.first;
}

void Age() {
	int N;
	cin >> N;

	vector<pair<int, string>> vc;
	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		vc.push_back(make_pair(age, name));
	}

	stable_sort(vc.begin(), vc.end(), compare);

	for (int i = 0; i < N; i++)
		cout << vc.at(i).first << ' ' << vc.at(i).second<<'\n';
}

/*
	library => stable_sort : 값이 만약 같다면, index가 빠른순으로 정렬해줌
*/