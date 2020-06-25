#include <bits/stdc++.h>
//12015�� ����
//https://eine.tistory.com/entry/%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-Longest-Increasing-Subsequence ����
using namespace std;

void LIS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector <int> vc;

	vc.push_back(INT_MIN);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp > vc.back()) {
			vc.push_back(temp);
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(vc.begin(), vc.end(), temp);
			*low = temp;
		}
	}
	cout << cnt;
}

/*
	N�� 10���̹Ƿ� �׳� O(n^2) ���� Time Limit Exceeded
	-> �̺� Ž���� �̿��ؾ� ��

	�˰��� ����Ʈ
	=> length�� ���� ����ؼ� DP�� ����ϴ� ���� �ƴ� LIS �迭 ��ü�� ����� ��
	=> �� �Է¹޴� ��� �����ϴ� ������ ���� ����!
	how?) �Է¹��� ���� LIS�� ������ ��(���� ū ��)���� ŭ -> �� �������� �־�
		  �Է¹��� ���� LIS�� ������ ������ ���� -> ����Ž���� ���� �־�� �ϴ� ��ġ���ٰ� �ٲپ��ָ� �� (lower_bound �̿�)
		  -> �̶�, �׷��� �ٲپ������ �ȵ��ݾ�! ��� ������ ��µ� ������ �츮�� ���ϴ°� LIS��ü�� �ƴ� LIS���� ������ '����'
		  -> ���� �̷��� �ص� ��.
*/