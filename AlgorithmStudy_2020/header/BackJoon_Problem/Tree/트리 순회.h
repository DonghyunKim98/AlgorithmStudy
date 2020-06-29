#include <bits/stdc++.h>
//1991번 문제
using namespace std;

//{left,right} , alphabet이 26개이므로 26개의 배열
int tree[26][2];
int N;

//root -> left -> right
void Preorder(int node){
	if (node == -1) return;

	cout << char(node + 'A');
	Preorder(tree[node][0]);
	Preorder(tree[node][1]);
}

//left->root ->right
void Inorder(int node) {
	if (node == -1) return;
	Inorder(tree[node][0]);
	cout << char(node + 'A');
	Inorder(tree[node][1]);
}

//left->right->root
void Postorder(int node) {
	if (node == -1) return;
	Postorder(tree[node][0]);
	Postorder(tree[node][1]);
	cout << char(node + 'A');
}


void TreeTravel() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		tree[root - 'A'][0] = left != '.' ? left-'A' : -1 ;
		tree[root - 'A'][1] = right != '.' ? right - 'A' : -1;
	}
	//언제나 root는 A
	Preorder(0);
	cout << '\n';
	Inorder(0);
	cout << '\n';
	Postorder(0);
	cout << '\n';
}

/*
	알고리즘 포인트
	1. PS에만 집중하자 굳이 BinaryTree를 구현할 이유가 없다. 
	알파벳만 들어온다는 것에 집중해서 배열을 구현하면 된다.
	2. 어찌됐든 문자열관련은 집중하고 집중해야 한다.
	ex) 시저 암호학
	char encrypted = (password-'A'+3)%26 +'A'; => 대문자
*/