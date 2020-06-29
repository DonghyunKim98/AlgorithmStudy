#include <bits/stdc++.h>
//1991�� ����
using namespace std;

//{left,right} , alphabet�� 26���̹Ƿ� 26���� �迭
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
	//������ root�� A
	Preorder(0);
	cout << '\n';
	Inorder(0);
	cout << '\n';
	Postorder(0);
	cout << '\n';
}

/*
	�˰��� ����Ʈ
	1. PS���� �������� ���� BinaryTree�� ������ ������ ����. 
	���ĺ��� ���´ٴ� �Ϳ� �����ؼ� �迭�� �����ϸ� �ȴ�.
	2. ����Ƶ� ���ڿ������� �����ϰ� �����ؾ� �Ѵ�.
	ex) ���� ��ȣ��
	char encrypted = (password-'A'+3)%26 +'A'; => �빮��
*/