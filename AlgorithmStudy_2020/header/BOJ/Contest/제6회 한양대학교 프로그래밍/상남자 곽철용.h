#include <bits/stdc++.h>
//17947�� 
using namespace std;
typedef pair<int, int> pii;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> vc(K);
	int cnt = 4 * N / K;
	for (int i = 0; i < K; i++) {
		//������ �������� �ʴ� ��� ���� ó��
		if (i != 0 && i <= (4 * N) % K) cnt++;
		vc[i] = cnt;
	}
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vc[n1 % K]--, vc[n2 % K]--;
	}
	int num1, num2;
	cin >> num1 >> num2;
	vc[num1 % K]--, vc[num2 & K]--;
	int gap = abs(num1 % K - num2 % K);

	//�������� ������ ���� �Է�
	vector<pii> vc2;
	for (int i = vc.size()-1; i >= 0; i--) {
		vc2.push_back({ i,vc[i] });
	}
	int answer = 0;
	int start = 0, end = 1;
	/*
		4 3 2 1 1 0 0 0
	*/
	while (1) {
		// ��ö�뺸�� gap���� ����
		if (vc2[start].first - vc2[end].first <= gap) {
			end++;
		}
		// ��ö�뺸�� gap�� ŭ
		else {
			int MIN = min(vc2[start].second, vc2[end].second);
			answer += MIN;
			vc2[start].second -= MIN, vc2[end].second -= MIN;
			if (vc2[start].second == 0) start++;
			if (vc2[end].second == 0) end++;
		}
		// ������ �����Ͱ� ������ �� -> Ż��
		if (end == vc2.size()) break;
	}
	answer = min(answer, M - 1);
	cout << answer;
}
