#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

//1927¹ø ¹®Á¦

void MinHeap() {
	int N;
	scanf_s("%d", &N);
	
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int temp;
		scanf_s("%d",&temp);
		if (temp == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}
	return;
}