#include <bits/stdc++.h>

using namespace std;

//1003�� ���� ->�¾���
//https://hongku.tistory.com/164 �� �ڵ�. -> ǥ�� �׸���! (��ȭ���� Ȯ���� �� �ִ� �ٸ� ���)

//Memoization�� ���� �迭 -> ��� ���Ҹ� ���ʿ� 0���� �ʱ�ȭ ��Ŵ���ν�  ���� ���� �ȵ��� Ȯ���ϴ� ready �迭�� ��� ��
int value[41] = { 0, };

int Calculate(int);

void Fibonacci() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//base case
	value[0] = 0;
	value[1] = 1;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) cout << "1 0\n";
		else if (temp == 1) cout << "0 1\n";
		else {
			Calculate(temp);
			cout << value[temp - 1] << " " << value[temp] << "\n";
		}
	}
}

int Calculate(int a) {
	if (a == 0 || a == 1) return value[a];
	else if (value[a] != 0) //�̹� ����� �Ǿ��ٴ� �ǹ� 
	{
		return value[a];
	}
	else {
		return value[a] =Calculate(a - 1) + Calculate(a - 2);
	}
}

/*
	�������
	1) '��Ģ'�� �ľ��ϴµ����� ���� ǥ�� ����
	2) Memorization�� �� �� �ݵ�� �迭 2���� �����ؼ�
	�ϳ��� value�� �ϳ��� �� value�� ä�������� Ȯ���ϴ� boolean type�� �迭�� ������ ������ ����
	3) return ������ ����ϸ� �ڵ带 1���̶� ���� �� �ִ�.
*/