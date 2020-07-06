#include <bits/stdc++.h>
const int MAX = 10000000;
using namespace std;



int solution(string numbers) {
	//1~999999 
	bool* prime = new bool[MAX];
	fill_n(prime, MAX, true);
	//1�� �Ҽ��� �ƴ�
	for (int i = 2; i <= MAX; i++) {
		if (prime[i] == false) continue;
		for (int j = i * 2; j <= MAX; j += i) 
			prime[j] = false;
	}

	
}

/*
	�˰��� ����Ʈ
	=> numbers�� �̿��ؼ� ���ڸ� ����� (x)
	=> ���ڰ� numbers���� �̿��ؼ� ������� �� �ִ��� check�Ѵ�(o)

	=> Binary Search���� ���ݰ��� ������ ���̵� ���
	-> ���� �������� ������ �ľ��ϰ� �� ������ ���� ���ǿ� �´��� Ȯ���Ѵ�(x)
	-> ������ ���� �����̿� �� �� �ִ��� �ľ��Ѵ�(o)
*/