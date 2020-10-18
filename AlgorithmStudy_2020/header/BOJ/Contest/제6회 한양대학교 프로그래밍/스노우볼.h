#include <bits/stdc++.h>
//17950번 문제
using namespace std;
const int m = 1000000007;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h, x;
	cin >> h >> x;

	long long answer = 0;
	long long i = 1;
	while (h > 0) {
		i *= x;
		int temp;
		cin >> temp;
		answer += (temp * i);
		i %= m;
		answer %= m;
		h--;
	}
	cout << answer;
}

/*
	알고리즘 포인트 
	=> 0.5초라는 것 그리고 제곱수를 연속해서 계속 쓸것이라는 것
	즉 이전에 계산한 제곱수를 버리지 않고 x만 곱하면 다음 제곱수로 이용할 수 있다는 것
	이를 이용해야 시간초과가 나오지 않는다.

	그리고 제발 long long 쓰자... 몇번을 틀리는 거냐 수학관련 문제에서
*/