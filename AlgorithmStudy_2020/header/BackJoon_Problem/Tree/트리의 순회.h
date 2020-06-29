#include <bits/stdc++.h>
//2263번 문제
//https://wjdgus2951.tistory.com/59 참고
using namespace std;
const int MAX = 100000 + 1;
int N;
vector<int> inOrder(MAX);
vector<int> postOrder(MAX);
vector<int> position(MAX);
void preOrder(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = postOrder[post_end]; //root는 항상 postOrder의 끝 값
	cout << root << ' ';

	int root_position = position[root]; //root 값이 있는 곳 inOrder 의 Idx 값 저장

	//left 변수는 root_position과 in_start간에 element가 몇개있는지를 확인하는 변수
	int left = root_position - in_start;

	//left 순회
	//이때 범위가 "left-1" 
	//why?) Inorder에서 in_start부터 root까지 left개 이므로
	//		순수한 left에 있는 원소의 개수는 left-1개.
	preOrder(in_start, root_position - 1, post_start, post_start + left - 1);
	//right 순회
	preOrder(root_position + 1, in_end, post_start + left, post_end - 1);
}



void TreeTravelsal() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	//Inorder input(left->root->right)
	for (int i = 0; i < N; i++)
		cin >> inOrder[i];

	//Postorder input(left->right->root)
	for (int i = 0; i < N; i++)
		cin >> postOrder[i];

	for (int i = 0; i < N; i++)
		position[inOrder[i]] = i; //idx저장
	//Preorder (root->left-right)
	preOrder(0, N-1, 0, N-1); 
}

/*
	알고리즘 포인트
	=> postorder의 마지막은 무조건 root 
	=> inorder에서 root를 기준으로 앞쪽이 left 오른쪽이 right
	=> 이걸 이용해야함. (재귀)
	
*/