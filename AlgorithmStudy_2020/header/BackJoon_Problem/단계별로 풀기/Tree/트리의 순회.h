#include <bits/stdc++.h>
//2263�� ����
//https://wjdgus2951.tistory.com/59 ����
using namespace std;
const int MAX = 100000 + 1;
int N;
vector<int> inOrder(MAX);
vector<int> postOrder(MAX);
vector<int> position(MAX);
void preOrder(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = postOrder[post_end]; //root�� �׻� postOrder�� �� ��
	cout << root << ' ';

	int root_position = position[root]; //root ���� �ִ� �� inOrder �� Idx �� ����

	//left ������ root_position�� in_start���� element�� ��ִ����� Ȯ���ϴ� ����
	int left = root_position - in_start;

	//left ��ȸ
	//�̶� ������ "left-1" 
	//why?) Inorder���� in_start���� root���� left�� �̹Ƿ�
	//		������ left�� �ִ� ������ ������ left-1��.
	preOrder(in_start, root_position - 1, post_start, post_start + left - 1);
	//right ��ȸ
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
		position[inOrder[i]] = i; //idx����
	//Preorder (root->left-right)
	preOrder(0, N-1, 0, N-1); 
}

/*
	�˰��� ����Ʈ
	=> postorder�� �������� ������ root 
	=> inorder���� root�� �������� ������ left �������� right
	=> �̰� �̿��ؾ���. (���)
	
*/