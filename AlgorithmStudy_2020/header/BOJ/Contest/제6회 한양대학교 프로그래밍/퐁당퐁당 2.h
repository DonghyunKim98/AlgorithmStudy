#include <bits/stdc++.h>
//17938�� ����
using namespace std;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int position, T;
	cin >> position >> T;
	int t = 1, before = 0, after = 0, cnt = 0;
	for (int i = 1; i <= T; i++) {
		//���� ������ ���� ���� count.
		//ó������ 2*N������ ���� �þ�� ���� 1��ŭ ����
		//2*N ���ĺ��ʹ� -1�� ���� -> 21��°�� code
		cnt += t;
		//before �ʱ�ȭ
		before = after;
		//after �ʱ�ȭ (cnt�� ������)
		after += cnt;
		//1->2*N �� �Ǿ����� -1�� ���ҷ� ��ȭ
		//2*N->1 �� �Ǿ����� 1�� ������ ��ȭ (�� ù°�� ����)
		if (cnt == 2 * N || (cnt == 1 && i != 1))
			t = -t;
		//���� �ѹ��� ���� 2*N��ŭ �����μ� position�ʱ�ȭ
		if (after > 2 * N)
			after -= 2 * N;
	}
	//���� 2���̱� ������ 2�� �����������.
	after = (after + 1) / 2;
	before = (before + 1) / 2;

	/*
		N=5
		before = 4
		after =  2
		-> �ɸ� ����� : 5 1 2
	*/
	if (before > after) {
		if (position > before || position <= after)  cout << "Dehet YeonJwaJe ^~^";
		else  cout << "Hing...NoJam";
	}
	/*
		N=5
		before = 2
		after = 4
		-> �ɸ� ����� : 3,4
	*/
	else {
		if (before < position && position <= after) cout << "Dehet YeonJwaJe ^~^";
		else cout << "Hing...NoJam";
	}
}