#include <iostream>
#include <algorithm>

using namespace std;
/*
	priority queue �� Ǫ�� ����... �� ���� �����ϰ� ����
*/
void SweepLineAlgorithmCustomer() {
	int N;
	cout << "�� �� ����� �մ��� �Գ���? :";
	cin >> N;
	int* CustomerIn = new int[N];
	int* CustomerOut = new int[N];
	for (int i = 0; i < N; i++) {
		int temp;
		cout << i + 1 << "��° �մ��� ��ÿ� �Գ���?" << endl;
		cin >> temp;
		CustomerIn[i] = temp;
		cout << i + 1 << "��° �մ��� ��ÿ� ��������?" << endl;
		cin >> temp;
		CustomerOut[i] = temp;
	}
	sort(CustomerIn,CustomerIn+N);
	sort(CustomerOut, CustomerOut + N);

	int count=0, max;

	for (int i = 0; i < N; i++) {

	}
}