#include <bits/stdc++.h>
//17939�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> vc(N + 1);
	//index �����ϴ� �迭!! => �ѹ� �ߴ� ��.
	vector<pair<int, int>> brr(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vc[i];
		brr[i] = { vc[i],i };
	}
	//������������ ����
	sort(brr.begin()+1, brr.end());
	reverse(brr.begin() + 1, brr.end());

	int start = 1, end = N, idx = 1, answer=0;
	while (start < end) {
		/*
			n+1��°�� ū ���� n��° ū������ �ڿ� ���´ٸ� ������ ��������
			�տ� ���´ٸ�, idx�� start���ٵ� �������� ���°� �߻�.
			-> idx�� ����÷���
		*/
		while (brr[idx].second < start) idx++;
		int MAX_IDX = brr[idx].second, MAX=brr[idx].first, tempSum = 0;
		for (int i = start; i <= MAX_IDX; i++) {
			tempSum += vc[i];
		}
		answer += (brr[idx].first * (MAX_IDX - start + 1) - tempSum);
		start = MAX_IDX + 1;
	}
	cout << answer;
}

/*
	�ݷ�ã��!! �׳� ������ ���� �װ͸� �ȴٰ� ������������ �پ��� ������ ����.
	�� ū���� �ڿ� ���´ٸ� ������ �ؾ��Ѵٴ� ����..
	�������� ��� ���� �ڵ���� ���鼭 �����ϰ� �غ�����.
	���ܿ� ���ؼ� ��� ����غ����ϰ� �����غ��� �Ѵ�.
*/