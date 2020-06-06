#include <bits/stdc++.h>
//7568번
//https://jaimemin.tistory.com/607 참고
using namespace std;


void BigBody() {
	//setting
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	//<<weight,height>,등수>
	vector<pair<pair<int, int>, int>> v;
	cin >> N;
	//input
	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;
		//초기 등수는 1등
		v.push_back(make_pair(make_pair(weight, height), 1));
	}

	//process
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			else if ((v[i].first.first < v[j].first.first) && (v[i].first.second < v[j].first.second)) v[i].second++;
		}
	}
	//output
	for (int i = 0; i < N; i++) {
		cout << v[i].second << " ";
	}
}