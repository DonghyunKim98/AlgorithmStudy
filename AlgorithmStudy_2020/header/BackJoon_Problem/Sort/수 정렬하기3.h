#include <bits/stdc++.h>
using namespace std;
//10989�� ���� ->�¾���(O)
//https://league-cat.tistory.com/4 �� ����

void Sort3() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	//array�� N��ŭ�� �Ҵ��ϸ� �޸��ʰ� ����� 
	//index�� data value�� ���� �����ϱ� �������� �ص� ��
	int* array = new int[10001]{ 0, };
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		array[temp]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (array[i] == 0) continue;
		else {
			for(int j=0;j<array[i];j++)
			cout << i<<"\n";
		}
	}
}

/*
	����� �� ��
	1) ����ð� ������ϱ�. 
	- �־��� �ð������� 3�� / �޸� ������ 8MB�̴�.
	- �־��� �Է°��� �ִ� ���� (Worst Case)�� 1000����.
	- ������ �˰����� O(n log n)�� �ϸ� 2000�� x 3 =6000������ �ۿ� Ŀ���� ����
	- �� �� ���� �˰����� �ʿ��ѵ�, �߿��Ѱ� �Է� �������� ������ 1���� 10000�����ۿ� �ȵȴٴ� ���� �̿��ؾ���!!
	2) <"�Է� �������� ����"�� index�� �ϴ� ���� �ƴ�, "�Է� �������� �ִ밪"�� index�� �ϴ°�!!>
	- index�� �ش��ϴ� ���� ������ �ش� index�� ��� �ִ����� ����ϴ� ���̴�!
*/