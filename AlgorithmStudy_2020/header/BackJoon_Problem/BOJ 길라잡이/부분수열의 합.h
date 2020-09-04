#include <bits/stdc++.h>
//1182�� ����
using namespace std;
int N, S;
vector<int> vc;
int ans = 0;
void DFS(int idx,int temp_sum) {
	if (idx == vc.size()) return;
	for (int i = idx; i < vc.size(); i++) {
		temp_sum += vc[i];
		if (temp_sum == S) ans++;
		DFS(i + 1,temp_sum);
		temp_sum -= vc[i];
	}
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}
	/*
		�κй迭 ����.
		i��° ������ �κй迭�� -> i��° ȥ�ڸ����� �̷���� �ִ���
							  -> [0,i-1]��°���� ������ �κй迭�� i�� �߰��߰ų�
							  -> �ٵ� ������ ���� �ȵǳ�... ��� �κй迭�� �� ������� �ҵ�=>O(n^2)

		=>�ܼ� �����ϰ� 2��ø �ݺ������� �����ص� ������, DFS�� �̿��ϴ� ���� ���� ���
	*/
	DFS(0,0);
	cout << ans;
}