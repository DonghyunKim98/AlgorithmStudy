#include <bits/stdc++.h>
//1654�� ����
using namespace std;

void LanCutting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	vector <long long> vc;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long temp;
		cin >> temp;
		vc.push_back(temp);
	}

	//parametric search
	sort(vc.begin(), vc.end());
	long long begin =1, end = vc[vc.size()-1];
	//while���� ������ �ٽ�
	//while ���� Ż�� �Ѵٴ� ���� end�� �� �۾����ٴ� ���� ���� ������ �� Ŀ���ٴ� �� . �̶� ������ ������ �ٷ� ��.
	//why? �ϴ��� �������ϱ� ���� cnt==N�� �����ϴ� begin�� end�� �𿩵��ݾ�? 
	//���� �� [100,105] ��� ���ڰ�. �׷��� �̶� �츮�� begin�� ��� Ű��Ŵϱ� end�� �����Ǿ�����.
	//���� begin�� end�� �ʰ��Ҷ��� end�� ����ϸ� end�� cnt==N�� �����ϴ� ������ ������. (�������� 105)
	while (begin<=end) {
		long long k = (begin + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < vc.size(); i++)
			cnt += vc.at(i)/ k;
		//�ڸ��� ��ġ�ų� ���� -> k ���� �÷��� �� -> begin �� ����
		if (cnt >= N) begin = k + 1;
		//�ڸ��� ���ڸ��� -> k ���� �ٿ� ���Ѿ� ��. ->end�� �Ʒ���.
		else end = k - 1;
	}
	cout << end;
	
}

/*
	�˰��� ����
	=> Parametric search https://coderkoo.tistory.com/8 ����
	=> ���� �ٽ� ������ https://navigator-ymin.tistory.com/7 ����


	�Ǽ��� �κ�
	-> Binary Search�� �����Ҷ� start�� 0���� ������ (1�� ����)
	-> �׻� ���� ���� ���ҿ� 1���� ���� ���� �߻��� ���̶�� �����Ѱ�. => ���� ū ���Ҹ� end�� �����
*/