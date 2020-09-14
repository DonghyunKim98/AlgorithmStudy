#include <bits/stdc++.h>
//1826�� ����
using namespace std;
const int MAX = 10000000 + 1;
typedef pair<int, int> pii;
int N,destination,fuel;
//��������
struct cmp {
	bool operator()(pii& a, pii& b) {
		return a.first > b.first;
	}
};
//��������
struct cmp2 {
	bool operator()(pii& a, pii& b) {
		return a.second < b.second;
	}
};
//ù��° pq -> �����Ҹ� �Ÿ������� ������������ ��ġ(min heap)
priority_queue<pii,vector<pii>,cmp> pq;
//�ι��� pq -> �� �� �ִ� �����Ҹ� �⸧�� ���� �� �ִ� ������ �������� ��ġ(max heap)
priority_queue<pii,vector<pii>,cmp2> pq2;


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
	cin >> destination >> fuel;
	int ans = 0;
	//�⸧�� ���������� �� �� ���� ������ �Ǹ� stop 
	//������������ �Ÿ��� destination�ε� ���� �⸧���� fuel�� destionation���� ������ �� �� �����Ƿ� �� �����Ҹ� �� ����� ��
	while (fuel < destination) {
		//������ �ִ� �⸧���� �� �� �ִ� �����Ҵ� �� �ִ´�
		while (!pq.empty() && fuel >= pq.top().first) {
			pq2.push(pq.top());
			pq.pop();
		}
		//�� �� �ִ� �����Ұ� ����! -> -1���
		if (pq2.empty()) {
			ans = -1;
			break;
		}
		//�� �� �ִ� �������� ���� �⸧�� ���� ���� �� �ִ� ������ ����
		fuel += pq2.top().second;
		pq2.pop();
		ans++;
	}
	cout << ans;
}

/*
	1. k��° �����Ҹ� �鸮�°�� -> ���� ���� �ִ� ������ k+1��°���� �� ���� ���
	=> �׷�����, k+1��° ���� ����� ������, k��° �����ҿ��� �ſ� ���� ������ ������ �� �ִٸ�
				�������
	
	�׷��ٸ� �켱������
	1) ���� ���� �����ұ��� �� �⸧�� ���� -> �鸲
	2) ���� ���� �����ұ��� �� �� ������ �̰����� �⸧�� ���� ������ �� �ִ� -> �鸲..?
	  -> �ܼ��� sort�� �̿��ؼ� �鸮�� �Ǵ°��ΰ�?
*/

/*
	<���� ����>
	1) ���� �ִ� ����� �� �� �ִ� �����Ҹ� ã�´�. 
		-> �̶� �� �� �ִ� �����Ұ� ���ٸ� -1�� ���
	2) �� �� �ִ� �������߿�, ���� �⸧�� ���� ���� �� �ִ� ������ �⸧�� �ִ´�.

	3) 1)->2) �� �ݺ��Ҷ� ���� �ܰ迡 �ִ� �����ҿ��� �� ���� ������ ���� �����Ƿ� �켱���� ť�� �̿��ؼ� �����Ѵ�.

	* �⸧�����ε� �Ÿ��� ������ �� �ִ�. �� �κ��� �������� ���Ѱ� ������.
*/