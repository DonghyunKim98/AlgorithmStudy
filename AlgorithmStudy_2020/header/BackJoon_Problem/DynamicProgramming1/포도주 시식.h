#include <bits/stdc++.h>
//2156�� ����
//https://mygumi.tistory.com/98 ����
using namespace std;

void WineTasting() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long* juice = new long long[N + 1];
	for (int i = 1; i <= N; i++) cin >> juice[i];
	//Memoization
	long long arr[10000 + 1];
	//base case
	arr[0] = 0;
	arr[1] = juice[1];
	if (N >= 2) arr[2] = juice[1] + juice[2];
	//DP
	for (int i = 3; i <= N; i++) {
		//OXOO �� ��� �� ?OXO�� ��츦 �����ش�.
		arr[i] = max(arr[i - 3] + juice[i - 1] + juice[i], arr[i - 2] + juice[i]);
		//�ٵ� �Ʒ��� ���� 2�� �ȸԴ� ��쵵 �����Ƿ�
		//�� �κи� ��� �ϸ�..
		arr[i] = max(arr[i], arr[i - 1]);
	}
	cout << arr[N];
}

/*
   100 400 2 1 4 200
a  O    O  X X O O
my O    O  X O X O

=>�� 2���� �ǳʶٴ� ��Ȳ�� cover���� ���ϰ� ����
=>�ᱹ arr[i]�� ä������ �������� ���� ���� ���� ���� ���ؾ���
*/