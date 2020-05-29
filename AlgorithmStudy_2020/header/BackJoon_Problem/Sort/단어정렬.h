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
	// Time Complextity = O(n^2) �� ��������... �� ���� ��� ����?
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
	1) ���Լ��� ���������� Ȱ���غ��Ҵ�!
	2) ���۸��� ���� duplicated word �� ����� ���� �˾Ƴ±��ߴµ� �� �ÿ�ġ�ʳ�... ��ƴ� ��
*/