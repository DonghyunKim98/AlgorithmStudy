#include <iostream>
#include <queue>
#include <functional>
using namespace std;

//11286번 문제 ->맞았음
//좀 다듬을 수도 있을 것 같다. 같은 것을 하는데 if else가 복잡함
void AbsouluteValueHeap() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//양수를 담는 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> Positive_pq;
	//음수를 담는 우선순위 큐
	priority_queue<int> Negative_pq;
	for (int i = 0; i < N; i ++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			//두 우선순위 큐가 모두 비어있을때
			if (Negative_pq.empty() && Positive_pq.empty()) cout << "0\n";
			else {
				//한쪽이 비었을 경우
				if (Negative_pq.empty()) {
					cout << Positive_pq.top() << "\n";
					Positive_pq.pop();
				}
				else if (Positive_pq.empty()) {
					cout << Negative_pq.top() << "\n";
					Negative_pq.pop();
				}
				//절대값이 차이가 날때
				else if((-1)*Negative_pq.top()!= Positive_pq.top() )
					//양수 쪽이 더 작을 때
					if ((-1) * Negative_pq.top() > Positive_pq.top()) {
						cout << Positive_pq.top() << "\n";
						Positive_pq.pop();
					}
					else {
						cout << Negative_pq.top() << "\n";
						Negative_pq.pop();
					}
				//차이가 안 날 때
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
