#include <bits/stdc++.h>
//10816�� ����
using namespace std;
vector <long long> card;
int N, M;

void NumberCard() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
	}
	sort(card.begin(), card.end());
	cin >> M;
	while (M > 0) {
		long long target;
		cin >> target;
		vector<long long>::iterator low;
		vector<long long>::iterator high;

		low = lower_bound(card.begin(), card.end(), target);
		high = upper_bound(card.begin(), card.end(), target);

		cout << high - low << ' ';
		M--;
	}
}

/*
	lower_bound �� upper_bound�� ����Ž������ ����ȴٴ°��� ó���˾Ҵ�...
*/