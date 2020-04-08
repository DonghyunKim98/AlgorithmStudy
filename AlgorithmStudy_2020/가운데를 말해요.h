#include <iostream>
#include <queue>
#include <functional>
using namespace std;

//1655�� ����
/*
	���̵�� -> Max heap �� Min heap�� ���� ���� ��������
	Max heap���� �߾Ӱ����� ū ������
	Min heap���� �߾Ӱ����� ���� ������ ������!
*/
void MedianValue() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//Max heap
	priority_queue<int> Max_pq;
	//Min heap
	priority_queue<int, vector<int>, greater<int>> Min_pq;
	for(int i=0; i<N; i++) {
		int temp;
		cin >> temp;
		//ó���� ���ؼ� �ϴ� ������ Max�ʿ� �ֱ�
		if (i == 0) {
			Max_pq.push(temp);
		}
		//Max heap�� Min heap�� ����� ���ؾ� �Ѵ�.
		//������ ���� ��
		else if (Max_pq.size() == Min_pq.size()) {
				//���� ���� ���� Minimum heap�� top���ٵ� Ŭ ���
				//������ {1} / {2} �̷��� �ִµ� 3�� ���� ���
			if (temp > Min_pq.top()) {
				Max_pq.push(Min_pq.top());
				Min_pq.pop();
				Min_pq.push(temp);
			}
			else //���� ���� ���� Minimun heap���� �۰ų� ���� ���
				 //���� �� {1} / {2} �̷��� �ִµ� 2�� ���� ���
			{
				Max_pq.push(temp);
			}
		}
		//������ �ٸ� �� -> Max���� Ŭ �� �ۿ� ���� (���� ���ǿ� ����)
		else
		{	//���� ���� ���� Maximum heap���ٵ� ���� ���
			if (temp < Max_pq.top()) 
			{
				Min_pq.push(Max_pq.top());
				Max_pq.push(temp);
				Max_pq.pop();
			}
			else //���� ���� ���� ũ�ų� ���� ���
			{
				Min_pq.push(temp);
			}
		}
		//������ Max heap�� top�� �߰����� �ǵ��� �Ѵ�.
		cout << Max_pq.top() << "\n";
	}
}