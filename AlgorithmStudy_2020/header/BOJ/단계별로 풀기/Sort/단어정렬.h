#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool comp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

void WordSort() {
	int N;
	cin >> N;
	vector <string> vc;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		vc.push_back(temp);
	}
	sort(vc.begin(), vc.end(), comp);
	// Time Complextity = O(n^2) 라서 안좋은데... 더 좋은 방법 없나?
	for (int i = 0; i < vc.size(); i++)
	{
		for (int j = 0; j < vc.size(); j++)
		{
			if (vc[i].compare(vc[j]) == 0) vc.erase(vc.begin()+j);
		}
	}
	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << "\n";
	}
}

/*
	1) 비교함수를 실전적으로 활용해보았다!
	2) 구글링을 통해 duplicated word 를 지우는 법을 알아냈긴했는데 영 시원치않네... 어렵다 ㅠ
*/