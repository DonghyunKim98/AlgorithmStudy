#include <iostream>
#include <queue>
#include <functional>
using namespace std;

//11286�� ���� ->�¾���
//�� �ٵ��� ���� ���� �� ����. ���� ���� �ϴµ� if else�� ������
void AbsouluteValueHeap() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//����� ��� �켱���� ť
	priority_queue<int, vector<int>, greater<int>> Positive_pq;
	//������ ��� �켱���� ť
	priority_queue<int> Negative_pq;
	for (int i = 0; i < N; i ++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			//�� �켱���� ť�� ��� ���������
			if (Negative_pq.empty() && Positive_pq.empty()) cout << "0\n";
			else {
				//������ ����� ���
				if (Negative_pq.empty()) {
					cout << Positive_pq.top() << "\n";
					Positive_pq.pop();
				}
				else if (Positive_pq.empty()) {
					cout << Negative_pq.top() << "\n";
					Negative_pq.pop();
				}
				//���밪�� ���̰� ����
				else if((-1)*Negative_pq.top()!= Positive_pq.top() )
					//��� ���� �� ���� ��
					if ((-1) * Negative_pq.top() > Positive_pq.top()) {
						cout << Positive_pq.top() << "\n";
						Positive_pq.pop();
					}
					else {
						cout << Negative_pq.top() << "\n";
						Negative_pq.pop();
					}
				//���̰� �� �� ��
				else {
					cout << Negative_pq.top() << "\n";
					Negative_pq.pop();
				}
			}
		}
		else {
			if (temp > 0) Positive_pq.push(temp);
			else Negative_pq.push(temp);
		}
	}

}
