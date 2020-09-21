#include <bits/stdc++.h>
//16465번 문제
using namespace std;
int N, M, L;
int arr[4];
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> L;
	int total = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[temp]++;
		total += temp;
	}
	if (total > M || ((M - total) % L != 0 && (total % L != 0))) {
		cout << -1;
	}
	else cout << total / L;
}

/*
	vc안에 있는 정수들을 이용해서
	그 합이 L이 되게 하면 된다. (그리고 정확히 L의 배수만큼 만들어야 한다.)

	근데 책의 너비가 고작 1,2,3뿐
*/