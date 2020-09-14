#include <bits/stdc++.h>
//1202번 문제
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N, K;
struct cmp {
	bool operator()(pll& a, pll& b) {
		return a.first > b.first;
	}
};

struct cmp2 {
	bool operator()(pll& a, pll& b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second < b.second;
	}
};

vector<int> vc_bag;
//min heap -> weight를 기준으로
priority_queue<pll,vector<pll>,cmp> pq_juerly;
//max heap -> value를 기준으로
priority_queue<pll, vector<pll>,cmp2> pq_juerly2;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		ll M, V;
		cin >> M >> V;
		pq_juerly.push({ M,V });
	}
	for (int i = 0; i < K; i++) {
		ll weight;
		cin >> weight;
		vc_bag.push_back(weight);
	}
	sort(vc_bag.begin(), vc_bag.end());
	long long ans = 0;
	for (int i = 0; i < vc_bag.size(); i++) {
		int current_bag = vc_bag[i];
		while (!pq_juerly.empty() && pq_juerly.top().first <= current_bag) {
			pq_juerly2.push(pq_juerly.top());
			pq_juerly.pop();
		}
		if (pq_juerly2.empty()) continue;
		ans += pq_juerly2.top().second;
		pq_juerly2.pop();
	}
	cout << ans;
}

/*
	작은 가방에 넣을 수 있는 물건들 중 최대한 큰 가치의 물건을 넣어야함.


	알고리즘 설명
	1. 입력 - 보석 : 무게순으로 오름차순으로 정렬
	        - 가방 : 무게순으로 오름차순으로 정렬
	2. 작은 가방에 들어갈 수 있는 보석들을 pq에 넣음
	3. pq에서 제일 가치가 큰 친구를 ans에 넣어줌
*/