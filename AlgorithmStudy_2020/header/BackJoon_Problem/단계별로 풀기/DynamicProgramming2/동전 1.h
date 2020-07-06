#include <bits/stdc++.h>

using namespace std;

//2293�� ���� ->�¾���(O)
//https://sihyungyou.github.io/baekjoon-2293/ ����.
void Coin1() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//n�� ������ ���� ���� , k�� ��ǥ�ϴ� �׼�
	int n, k;
	cin >> n >> k;
	int* coins = new int[n] {0, };
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins[i] = temp;
	}
	//Memoization & Base Case
	//��ġ�� ���� 10000����  �� �ѱ� ������ 10001������ setting.
	int count[10001] = { 0, };
	count[0] = 1;
	//for���� ��ġ�� �޶���!! -> algorithm �ٽ� ����Ʈ
	for (int i = 0; i < n; i++) {
		for(int j=coins[i];j<=k;j++){
			if (j - coins[i] >= 0) {
				count[j] += count[j - coins[i]];
			}
		}	
	}
	cout << count[k]<<"\n";
}

/*
	�������
	1) ���� �˰� �ִ� ������ �����ҷ��� ����� ��������. 
	���� ��� ������ set�� �̿��ؼ� ���� "���"���� ���� ����̴�.
	�� 1+2 �� 2+1�� �ٸ��� ���ٴ� ��. ������ ������ 2���� ���� ����϶� ��!
	2) �̸� ��� �ذ��߳ĸ� ��ø�� for�� �ȿ��� 
	���� ������ int j=coins[x] �� �������μ� �ѹ� �� ������ �ٽô� �Ⱦ��°ɷ� ó��!!
	(�׷��� ���Ӱ� ������ ������ �̿��ϸ� �Ǵϱ�!)
*/
