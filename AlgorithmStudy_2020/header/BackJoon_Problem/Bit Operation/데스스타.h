#include <bits/stdc++.h>
//11811�� ����
using namespace std;
const int MAX = 1000 + 1;
int N;
int Array[MAX];

void DeathStar() {
	//setting
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input & process
	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (i == j) continue;
			Array[i] = Array[i] | temp;
		}
	}


	//output
	for (int i = 1; i <= N; i++) {
		cout << Array[i]<<" ";
	}
}

/*
	������) ������ ���� ������� ��� �������� ��.
	=>�� ù ����: ����
	=>���� �� : ������ ���� Ȱ���Ͽ� ��Ʈ������ ��

	�����) �޸� ������ �־ �� �ѹ��� ó���ϰ� �� ���� �ڷ�� ���� ������ ������ ����.
	=> �� �������� ���
*/