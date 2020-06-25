#include <bits/stdc++.h>
//1300�� ����
//https://jaimemin.tistory.com/988 ����
using namespace std;

void KthNumber() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int begin = 1, end = K;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			//mid ���� ���� j�� ��(i*j <=mid)
			//N�� ���� Ŀ����, mid/i�� N���� Ŀ�� �� ����(j�� �ִ� ���� N�̹Ƿ� N���� �ʰ��� ���� ����)
			cnt += min(mid / i, N); 
		if (cnt <= K)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	cout << begin;
}

/*
	1 2 3
	2 4 6  => 1 2 2 3 3 4 '6' 6 9
	3 6 9

	�����ϰ� �־ �� �ڸ��� ������ ���ϴ°��� ����
	�׷� ��¼��?

	�˰��� ����Ʈ
	=> ��ȸ�ϸ鼭 ������ ���ϴ°� �ƴ�, �迭�� �� ���� i*j���� �̿�
	=> '��'�̶�� ������ �̿��ϸ� �ѹ��� �� �� ����.
	=> �������� ����ϴ°��� begin
	why?) 
*/