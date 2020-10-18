#include <bits/stdc++.h>
//2565�� ����
using namespace std;

void ElectricWire() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	//{index,value}
	vector<pair<int, int>> vc;
	for (int i = 0; i < N; i++) {
		int index, value;
		cin >> index >> value;
		vc.push_back(make_pair(index, value));
	}
	sort(vc.begin(), vc.end());

	int MAX = 0;
	vector<int> length(N);
	for (int i = 0; i < N; i++) {
		length[i] = 1;
		for (int k = 0; k < i; k++) {
			if (vc.at(i).second > vc.at(k).second) length[i] = max(length[i], length[k] + 1);
		}
		MAX = max(length[i], MAX);
	}
	//MAX�� ����µ� �̿���� ������ ����??(O)
	//���ص��� ������ MAX�� �̿�? (O)
	cout << N-MAX;
}