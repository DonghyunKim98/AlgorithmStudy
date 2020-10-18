#include <bits/stdc++.h>
//1966�� ����
using namespace std;

void PrinterQueue() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int N, M;
		cin >> N >> M;
		//<�߿䵵,����index>
		vector<pair<int, int>> vc;
		for (int i = 0; i < N; i++) {
			int majority;
			cin >> majority;
			vc.push_back(make_pair(majority, i));
		}
		int count = 0;
		while (true) {
			
			//���� �� �տ� �ִ� ������ majority�� ���� ������ Ȯ��
			int current_majority = vc.at(0).first;
			bool is_top = true;
			for (int i = 1; i < vc.size(); i++) {
				//���� �ڿ� �� ū�� ����
				if (vc.at(i).first > current_majority) {
					is_top = false;
					//�� �տ� �ִ� ���Ҹ� �� �ڷ� ������ �� �տ� �ִ� ģ�� ����
					vc.push_back(vc.at(0));
					vc.erase(vc.begin());
					break;
				}
			}
			//���� �� �տ� �ִ� �ְ� Ȯ���ϰ� ���� �켱������ ����!! =>���
			if (is_top) {
				count++;
				if (vc.at(0).second == M) {
					cout << count << '\n';
					break;
				}
				vc.erase(vc.begin());
			}
		}
		T--;
	}

}

/*
	�켱���� ť?? => �׷��� �Ǹ� ���� ���� ������ ������ �Ǿ� ��.
	ť => ��� ���� ������ �ȵ�.
	���ͷ� ������ ��������!! -> ���� N�� �ִ밪�� 50�̱⶧���� �ð��ʰ��� �ȳ�.

	<�켱���� ť �̿� Ǯ��>
	->http://melonicedlatte.com/algorithm/2018/02/18/230705.html
	-> �켱���� ť'��'�� ��������� index�� ���� ������ ������ �Ǵ� ���� �ذ��� ���� ������
	-> �̸� �ذ��ϱ� ���� ť�� �켱���� ť�� ���ÿ� Ȱ���ؼ�
	-> ť�� {�߿䵵,���� index} �켱���� ť�� {�߿䵵}����
	-> �׸��� queue.top.first �� pq.top �� ������ ��� (count up)
	-> �ƴ϶�� queue�� �ڷ� ����
	-> �� pq�ʿ� index�� �ο����� ����!! (index�� ���� ������ �ȵǰ�!!)
*/