#include <bits/stdc++.h>
//11653번 문제
using namespace std;
const int MAX = 10000000 + 1;

void Facorization() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 2; i <= sqrt(N); i++) {
		while (N % i == 0) {
			cout << i<<'\n';
			N /= i;
		}
	}
	//처음부터 소수여서 나온게 없을땐
	if (N != 1) cout << N << '\n';
}

//시간이 고작 1초. O(n)만으로도 부족.