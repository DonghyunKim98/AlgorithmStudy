#include <bits/stdc++.h>
//3036¹ø ¹®Á¦
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void Ring() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int* root = new int[N];
	for (int i = 0; i < N; i++)
		cin >> root[i];

	int numerator = root[0];
	for (int i = 1; i < N; i++) {
		int denominator = root[i];
		int great_common_factor = gcd(numerator, denominator);
		cout << numerator / great_common_factor << '/' << denominator / great_common_factor << '\n';
	}
}