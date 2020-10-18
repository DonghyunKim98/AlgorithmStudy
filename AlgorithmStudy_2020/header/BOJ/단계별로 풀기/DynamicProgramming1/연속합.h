#include <bits/stdc++.h>
//1912¹ø ¹®Á¦
using namespace std;

void SequenceTotal() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr.at(i);

	//DP
	int best = arr.at(0), sum =arr.at(0);
	for (int i = 1; i < N; i++) {
		sum = max(arr.at(i), sum + arr.at(i));
		best = max(best, sum);
	}
	cout << best;
}