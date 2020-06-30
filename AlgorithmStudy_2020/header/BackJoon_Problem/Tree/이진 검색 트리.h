#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
//5693번 문제
using namespace std;
const int MAX = 1000000;
int preOrder[MAX];
int position[MAX];

void PostOrder(int pre_start, int pre_end) {
	if (pre_start > pre_end) return;
	if (pre_start == pre_end) {
		cout << preOrder[pre_start]<<'\n';
		return;
	}
	int root = preOrder[pre_start];
	int right_start=pre_end+1;
	//left leaf만 있을때를 생각해야함.
	for (int i = pre_start + 1; i <= pre_end; i++) {
		if (preOrder[i] > preOrder[pre_start]) {
			right_start = i;
			break;
		}
	}
	PostOrder(pre_start + 1, right_start - 1);
	PostOrder(right_start, pre_end);
	cout << root << endl;
}

void BinarySearchTree() {
	int idx = 0;
	int temp;
	while (scanf("%d", &temp) == 1) {
		preOrder[idx] = temp;
		idx++;
	}
	PostOrder(0, idx-1);
}


/*
	알고리즘 포인트
	-> 집어넣기!!
	-> root -> left -> right 로 주어진 것을
	-> left -> right ->root 로 변환할때
	맨 앞은 root이고 root보다 커지는 순간이 right임을 이용해서 배열을 순환하면서 확인한다.
	단 이 방법은 O(n^2) 이 걸리긴 하는데, 노드의 개수가 10000개 이하니깐..
*/