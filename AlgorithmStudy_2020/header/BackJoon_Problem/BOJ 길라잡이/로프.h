#include <bits/stdc++.h>
//2217�� ����
using namespace std;
vector<int> vc;
typedef long long ll;
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	sort(vc.begin(), vc.end(),greater<int>());
	ll result=0;
	for (int i = 0; i < N; i++) {
		//i��° rope���� ��������� ��ƿ �� �ִ� �ִ� �� => vc[i]*(i+1)
		ll sum = vc[i] * (i + 1);
		//������ ��ƿ �� �ִ� �պ��� ũ��! �׷� �־�~~
		if (sum > result) result = sum;
	}
	cout << result;
}

/*
	�������� �׸���. ��ƴ�
*/