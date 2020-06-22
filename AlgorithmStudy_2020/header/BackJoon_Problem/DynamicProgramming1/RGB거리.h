#include <bits/stdc++.h>
//1149번 문제
using namespace std;

void RGBDistance() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	//0 -> red 1 ->green 2->blue
	int arr[1001][3];
	for (int i = 1; i <= N; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		if (i == 1) {
			arr[1][0] = red;
			arr[1][1] = green;
			arr[1][2] = blue;
		}
		else {
			arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + red;
			arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + green;
			arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + blue;
		}
	}
	cout << min(min(arr[N][0], arr[N][1]), arr[N][2]);
}


/*
	직전의 것이 RGB중 무엇인지만 생각하면 됨.
*/