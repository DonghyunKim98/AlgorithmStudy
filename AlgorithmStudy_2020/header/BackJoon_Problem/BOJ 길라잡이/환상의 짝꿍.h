#include <bits/stdc++.h>
//15711번 문제
using namespace std;
typedef long long ll;
const int MAX = 2000000 + 1;
bool is_prime[MAX];
vector<ll> prime_num;

bool isPrime(ll num) {
	for (int i = 0; i < (int)prime_num.size() && (ll)prime_num[i] * prime_num[i] <= num; i++) {
		if (num % prime_num[i] == 0) return 0;
	}
	return 1;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(is_prime, true, sizeof(is_prime));
	for (ll i = 2; i < MAX; i++) {
		//이미 합성수로 판별남 -> continue
		if (!is_prime[i]) continue;
		prime_num.push_back(i);
		for (ll j = 2 * i; j < MAX; j += i) {
			is_prime[j] = false;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		if (a + b < 4) {
			cout << "NO\n";
			continue;
		}
		if ((a + b) % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		if (isPrime(a + b - 2)) cout << "YES\n";
		else cout << "NO\n";
	}
}

/*
	배열의 원소가 200조나 되는것을 생성할수 없다. 즉 200조까지 전부 소수인지 판명하는 것은 불가능
	=> 그럼 어떻게 특정 수가 소수의 합으로 이루어지는 지 알지?
	=> 일단 골드바흐의 추측으로 4이상의 짝수는 무조건 됨
	=> 4이상의 홀수의 경우엔?
	=> 무조건 "2 + 소수" 꼴 이여야 4이상의 홀수를 만들 수 있음 (2이상의 소수는 다 홀수이기때문)
	=> 그럼 a+b 에서 2를 뺀값이 소수인지를 판별하면 됨
	=> how?) 내가 미리 구해놓은 소수들로 나누어 떨어지는지 확인!
	=> 어떤 수가 합성수라면 소인수의 최대 중간값은 root(어떤수)임을 이용!
	

	정말 수학스러운 문제.
*/