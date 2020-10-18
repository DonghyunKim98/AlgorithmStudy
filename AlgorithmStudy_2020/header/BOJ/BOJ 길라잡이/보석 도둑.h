#include <bits/stdc++.h>
//1202�� ����
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
//min heap -> weight�� ��������
priority_queue<pll,vector<pll>,cmp> pq_juerly;
//max heap -> value�� ��������
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
	���� ���濡 ���� �� �ִ� ���ǵ� �� �ִ��� ū ��ġ�� ������ �־����.


	�˰��� ����
	1. �Է� - ���� : ���Լ����� ������������ ����
	        - ���� : ���Լ����� ������������ ����
	2. ���� ���濡 �� �� �ִ� �������� pq�� ����
	3. pq���� ���� ��ġ�� ū ģ���� ans�� �־���
*/