#include <bits/stdc++.h>
//1904번 문제
using namespace std;
const int MAX = 1000000 + 1;
int N;
//Memoization
long long arr[MAX];

int DP(int idx) {
	if (idx == 1 || idx == 2) return arr[idx] % 15746;
	else if (arr[idx] != 0) return arr[idx] % 15746;
	else return arr[idx]= (DP(idx-1)%15746+DP(idx-2)%15746)%15746;
}

void Tile() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//base Case
	arr[1] = 1;
	arr[2] = 2;

	//input
	cin >> N;

	cout << DP(N);
}


/*
	점화식 => an = a(n-1) + a(n-2)
	why?) 직전의 것에 1을 붙인다 -> a(n-1) // 직전의 것에 0을 붙인다 -> a(n-2)
*/