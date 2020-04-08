#include <iostream>
#include <queue>
#include <functional>
using namespace std;

//1655번 문제
/*
	아이디어 -> Max heap 과 Min heap을 따로 따로 구성하자
	Max heap에는 중앙값보다 큰 값들이
	Min heap에는 중앙값보다 작은 값들이 들어가도록!
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
		//처음에 한해서 일단 무조건 Max쪽에 넣기
		if (i == 0) {
			Max_pq.push(temp);
		}
		//Max heap과 Min heap의 사이즈를 비교해야 한다.
		//사이즈 같을 때
		else if (Max_pq.size() == Min_pq.size()) {
				//새로 들어온 값이 Minimum heap의 top보다도 클 경우
				//예를들어서 {1} / {2} 이렇게 있는데 3이 들어온 경우
			if (temp > Min_pq.top()) {
				Max_pq.push(Min_pq.top());
				Min_pq.pop();
				Min_pq.push(temp);
			}
			else //새로 들어온 값이 Minimun heap보다 작거나 같은 경우
				 //예를 들어서 {1} / {2} 이렇게 있는데 2가 들어온 경우
			{
				Max_pq.push(temp);
			}
		}
		//사이즈 다를 때 -> Max쪽이 클 수 밖에 없음 (문제 조건에 의해)
		else
		{	//새로 들어온 값이 Maximum heap보다도 작은 경우
			if (temp < Max_pq.top()) 
			{
				Min_pq.push(Max_pq.top());
				Max_pq.push(temp);
				Max_pq.pop();
			}
			else //새로 들어온 값이 크거나 같은 경우
			{
				Min_pq.push(temp);
			}
		}
		//언제나 Max heap의 top이 중간값이 되도록 한다.
		cout << Max_pq.top() << "\n";
	}
}