#include <bits/stdc++.h>
//1644번 문제
using namespace std;
const int MAX = 4000000 + 1;
int N;
bool is_prime[MAX];
vector<int> prime_num;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	//base case
	fill_n(is_prime, MAX, true);
	for (int i = 2; i <= N; i++) {
		//이미 합성수로 판별남 -> continue
		if (!is_prime[i]) continue;
		//i가 소수라면, vector에 집어넣고 i*2부터 [i*3,i*4...,N]까지 합성수라고 진행
		prime_num.push_back(i);
		for (int j = 2 * i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}
	int ptr1 = 0, ptr2 = 0;
	int ans = 0, temp_sum = 0;
	while (1) {
		//부분합이 큼 -> 왼쪽 포인터를 한칸 오른쪽으로 옮김 (부분합에선 왼쪽 포인터가 옮기기 전에 해당하는 값을 빼줌)
		if (temp_sum >= N) {
			temp_sum -= prime_num[ptr1++];
		}
		//오른쪽 포인터가 끝까지 옮 -> 탈출
		else if (ptr2 == prime_num.size()) break;
		//오른쪽 포인터가 끝까지 오진 않음 -> 포인터에 해당하는 값을 sum에 추가하고 한칸 옮김
		else temp_sum += prime_num[ptr2++];

		//위의 결과가 N과 같다면 ans 추가
		if (temp_sum == N) ans++;
	}
	cout << ans;
}

/*
	Two pointer method(두 포인터 기법) 을 이용한 대표적인 문제
	=> 부분배열의 합이 특정 숫자 값과 같은 부분배열 찾기.
	=> 왼쪽, 오른쪽 포인터를 이용해서 진행
	=> 만약 특정 숫자 값을 넘었다면, 왼쪽포인터를 한칸 오른쪽
	=> 넘지 않았다면, 오른쪽포인터를 한칸 오른쪽
	=> 결과적으론 왼쪽포인터, 오른쪽포인터 둘다 전체 배열을 1번만 살펴보므로 O(N)이 된다.
*/