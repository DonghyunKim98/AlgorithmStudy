#include <bits/stdc++.h>
//11401번 문제
//https://kyunstudio.tistory.com/60 참고
//solution -> 페르마의 소정리
#define m 1000000007;
const int MAX = 4000000 + 1;
typedef long long ll;
using namespace std;
ll fac[MAX], inv[MAX], N, K;
ll pow_(ll x, ll y) {
	if (y == 0) return 1;
	else if (y == 1) return x;
	if (y % 2 == 1) return (pow_(x, y - 1) * x) % m;
	ll half = pow_(x, y / 2) % m;
	return (half * half) % m;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//base case
	fac[1] = 1;
	//memoizaition
	for (int i = 2; i < MAX; i++) {
		fac[i] = (fac[i - 1] * i) % m;
	}
	//base case
	//a^(p-2) = A^-1 (mod p) 을 이용
	//분할정복을 통해 빠르게 구한다.
	inv[MAX - 1] = pow_(fac[MAX - 1], 1000000007 - 2);
	//memoization
	//A^-i = A^-(i+1) * (i+1) 이므로 내림차순으로 계산
	for (int i = MAX - 2; i > 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % m;
	}
	cin >> N >> K;
	if (N == K || !K) {
		cout << 1;
		return;
	}
	ll r = (fac[N] * inv[N - K]) % m;
	r = (r * inv[K]) % m;
	cout << r;
}

/*
	p가 소수 & p가 a의 배수가 아님
	=> a^(p-1) = 1 (mod p)
	=> aXa^(p-2) = 1 (mod p) 
		-> a의 p-1승을 2번 곱한거니깐
	=> a^(p-2) = A^-1 (mod p)
		-> 2번째 식을 양변을 A로 나눈 값
*/