#include <bits/stdc++.h>
//1016번 문제
using namespace std;
const int MAX = 1000+1;
typedef long long ll;
bool result[1000001] = { false };
ll num[1000001] = { 0 };


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll sq_max = (ll)sqrt(b);					//범위 내 제곱값이 될 수 있는 가장 큰 수
	ll cntNum = 0;								//제곱들의 개수
	for (ll i = 2; i <= sq_max; i++) {
		num[i] = i * i;
		cntNum++;
	}
	int cnt = 0;								//범위 내 제곱의 수로 나누어 떨어지는 수
	for (int i = 2; i < cntNum +2; i++) {
		ll div_min = a;							//div_min을 범위의 최소값 min으로 둔 후
		if (div_min % num[i] != 0)				//div_min이 제곱수로 나누어 지지 않는다면
			div_min = (a / num[i] + 1) * num[i];//최소값을 제곱근으로 나눈 몫에 +1후 다시 곱해서 범위 안의 값으로 바꿈

		for (ll tmp = div_min; tmp <= b; tmp += num[i]) {//num[i]로 나누어지는 div_min을 count한다
			if (!result[tmp - a]) {
				result[tmp - a] = true;
				cnt++;
			}
		}
	}
	cout << b - a + 1 - cnt;
}

/*
	idea 1 
		=> 시간은 2초고, "환상의 짝꿍"에서 썼던 방법을 써도 1백만 X 10만 으로 1조가 넘어감
		=> 따라서, "주어진 범위" 내에서만 제곱수로 나누어지는지 안 나누어지는지를 확인
	idea 2
		=> 나누어질 수 있는 제곱수의 최대값은 주어진 간격의 최대값의 root 값
	idea 3
		=> 소수를 찾듯이 제곱수들을 이용해서 나누어지는 것들을 거른다 ("전체-반례" 논리 이용)
*/