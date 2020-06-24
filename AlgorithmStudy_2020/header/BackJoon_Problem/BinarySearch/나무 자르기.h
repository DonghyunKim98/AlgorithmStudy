#include <bits/stdc++.h>
//2805�� ����
using namespace std;

void TreeCutting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	long long M;
	cin >> N >> M;
	vector<long long>vc;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vc.push_back(temp);
	}

	//parametric search
	sort(vc.begin(), vc.end());
	long long begin = 0, end = vc.at(vc.size()-1);
	/*long long result = -1;*/
	while (begin<=end) {
		long long k = (begin + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < vc.size(); i++)
			if (vc[i] > k) cnt += vc[i] - k;

		if (cnt >= M) { 
			/*if (result < k)
				result = k;*/
			begin = k + 1; 
		}
		else end = k - 1;
	}
	cout << end;

}

/*
	https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-2805-%EB%82%98%EB%AC%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0
	=>upper_bound�� ���� �̾߱� (lower_bound�� �ƴ϶�)
	�� cnt>=M �϶�, cnt==M�϶��� lower bound�� ���ϱ� ���ؼ�, ������ k������ �۾Ҵٸ� k�� �������ִ� ��.
	�ֳ��ϸ� begin�� ��� Ŀ���Ŵϱ�, k���� ��� �����Ұ�.
	�׷��� begin==end �̸� (�̶��� �� while�� Ż���ϱ� ���� loop) cnt==M�� ������Ű�� ���� ū k ���̴ϱ�
	�̶��� ����!
*/