#include <bits/stdc++.h>
//2981�� ����
//https://sihyungyou.github.io/baekjoon-2981/ ����
using namespace std;
const int MAX = 1000000000+1;

//��Ŭ���� ȣ����
int gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

void Check() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<long long> vc(N);
	for (int i = 0; i < N; i++) 
		cin >> vc.at(i);

	sort(vc.begin(), vc.end());

	//���� �߿��� �ִ� �����.
	int max_common_factor = vc.at(1) - vc.at(0);
	for (int i = 2; i < N; i++) {
		max_common_factor = gcd(max_common_factor, vc.at(i) - vc.at(i - 1));
	}

	vector <int> answer;
	for (int i = 2; i <= sqrt(max_common_factor); i++) {
		if (max_common_factor % i == 0) {
			answer.push_back(i);
			answer.push_back(max_common_factor / i);
		}
	}
	
	answer.push_back(max_common_factor);
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (auto u : answer)
		cout << u << ' ';
}

/*
	�������� ���� ������ ����
		v[i]  = m* temp[i] +r
	=>  v[i] - v[i-1] = m*(temp[i] - temp[i-1]) + (r-r)
	�� �������� m�� ���ϴ°� ����!
*/