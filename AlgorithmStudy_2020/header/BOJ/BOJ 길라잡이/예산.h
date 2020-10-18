#include<bits/stdc++.h>
//2512�� ����
using namespace std;
typedef long long ll;
int N;
vector<ll> vc;
ll M;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	ll total = 0;
	ll max_budget = 0;
	for (int i = 1; i <= N; i++) {
		ll temp;
		cin >> temp;
		max_budget = max(max_budget, temp);
		vc.push_back(temp);
	}
	cin >> M;
	ll left = 0, right = max_budget;
	ll result;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll total = 0;
		for (int i = 0; i < vc.size(); i++) {
			total += min(vc[i], mid);
		}
		if (total <= M) {
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result;
}

/*
	�ִ� �ּڰ� => Binary Search�� ���� ���� ���ø���!
*/