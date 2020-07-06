#include <bits/stdc++.h>
//1011번
//https://jm-park.github.io/algorithm/2018/08/01/%EB%B0%B1%EC%A4%80-1011%EB%B2%88-Fly-me-to-the-Alpha-Centauri.html 참고
using namespace std;

void Fly() {
	int T;
	cin >> T;
	while (T > 0) {
		double x, y;
		cin >> x >> y;
		double i = 1, cnt = 0;

		// y-x보다 큰 제곱수i 구하기
		for (;; i++) {
			if (i * i > y - x)
				break;
		}

		// y-x가 i-1의 제곱수일 경우 
		if ((i - 1) * (i - 1) == y - x)
			cnt = 2 * (i - 1) - 1;
		// i-1의 제곱수 < y-x <= 중간지점 인 경우
		else if ((i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2) >= y - x)
			cnt = 2 * i - 2;
		// 중간지점 < y-x < i의 제곱수 인 경우
		else
			cnt = 2 * i - 1;
		cout << cnt << "\n";
		T--;
	}
}