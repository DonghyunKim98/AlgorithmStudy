#include <iostream>
#include <algorithm>

using namespace std;
/*
	priority queue 로 푸는 문제... 흑 좀더 공부하고 오자
*/
void SweepLineAlgorithmCustomer() {
	int N;
	cout << "그 날 몇명의 손님이 왔나요? :";
	cin >> N;
	int* CustomerIn = new int[N];
	int* CustomerOut = new int[N];
	for (int i = 0; i < N; i++) {
		int temp;
		cout << i + 1 << "번째 손님은 몇시에 왔나요?" << endl;
		cin >> temp;
		CustomerIn[i] = temp;
		cout << i + 1 << "번째 손님은 몇시에 떠났나요?" << endl;
		cin >> temp;
		CustomerOut[i] = temp;
	}
	sort(CustomerIn,CustomerIn+N);
	sort(CustomerOut, CustomerOut + N);

	int count=0, max;

	for (int i = 0; i < N; i++) {

	}
}