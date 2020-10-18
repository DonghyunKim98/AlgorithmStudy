#include <bits/stdc++.h>
//17944¹ø ¹®Á¦
using namespace std;


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); 

	int N, T;
	cin >> N >> T;
	int* arr = new int[4 * N - 2 + 1];
	for (int j = 1; j <= 2 * N; j++)
		arr[j] = j;
	for (int j=2*N+1 ; j<= 4*N-2 ; j++)
		arr[j] = (4*N)-j;
		

	cout << arr[T % (4 * N-2)];

}

/*
	[1 2 3 4 5 6 5 4 3 2] [1 2 3 4 5 6 5 4 3 2 1]
idx  1 2 3 4 5 6 7 8 9 10
*/