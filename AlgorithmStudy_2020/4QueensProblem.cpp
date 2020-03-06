/*#include <iostream>

using namespace std;
//���� ������ ���� value
int Count;
int n;
//ü���� ĭ�� indexing �ϱ����� �迭 3����
//	1) col -> ��
//	2) diag1 -> ����� �밢��
//	3) diag2 -> ������ �밢��
//	�׸��� �ʱ�ȭ ���ϸ� �����Ҵ��ؼ� �ּҰ� Ƣ��� ������ ��ü 0���� �ʱ�ȭ!!
//	diag1�� diag2�� ��쿡�� index�� 4������ �ִ°� �ƴ϶� 6�����ִ�!!!


int* col = new int[4]{ 0, };
int* diag1 = new int[6]{ 0, };
int* diag2 = new int[6]{ 0, };
//Problem�� Ǫ�� �Լ�
void search(int);
int main() {
	//�⺻ �ʱ�ȭ
	n = 4;
	Count = 0;
	//function call
	search(0);
	cout << "4*4�� ü���ǿ��� ���� �������� �ʴ� ���� ���� �� �ִ� ����� " << Count << "�� �Դϴ�.";
}
//x�� ���� index, y�� ���� index , n�� ü������ ũ��
void search(int y) {
	if (y == n) {
		Count++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x + n - 1 - y]) continue; //�ϳ��� 1�̸� ���� �ü� ����! (�������������� �θ�� ���ư�)
		col[x] = diag1[x + y] = diag2[x + n - 1 - y] = 1; //���� �����ִ�! (����)
		search(y + 1); // �����ϴ� Ž��
		col[x] = diag1[x + y] = diag2[x + n - 1 - y] = 0; //���󺹱� (������ �ϴ� ������ �ִٰ� ����)
	}

}
*/
/*
	�ظ̴� ����: 1) or �����ڸ� �����... �ϳ��� false�� false���� �˾Ҵµ� �ϳ��� true�� true ����.
				 2) 0�̸� ���� ���� (queen�� �����Ҽ��ִ� ��) 1�̸� �� �� �ִٴ� �͵� ��Ȯ�� ���� X
				 3) �迭�� �������� �Ҵ������� �ƹ��͵� �ʱ�ȭ���� ������ ��� element�� �ּҰ��� �Ҵ��
				   -> �׷��� ��ü �迭�� 0���� �Ҵ��� �ؾ�����.
			     4)  diag1 �� diag2�� ��� index�� n��ŭ�� �ƴ�.... index�� �׻� n������ �ִٰ� ���� X!
	Algorithm Point : Backtracking�� �⺻!! �����ϴٸ� ���� (���� ������ ���� X) �������� �ʴٸ� �Ȱ���(���� ������ ����)
*/