#include <bits/stdc++.h>

using namespace std;

void Longest_Increasing_Subsequence() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << "��� ���Ұ� �ֽ��ϱ�?:";
	int N;
	cin >> N;
	int* arr = new int[N];
	cout << "���Ҹ� �Է��ϼ���\n";
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	//Memoization �� ��ȭ���� �ٽ� �迭
	int* length = new int[N];
	/*
	// O(n^2) �ݺ���
	for (int k = 0; k < N; k++) {
		//���� �� index���� �����ϴ� ���
		length[k] = 1;
		for (int i = 0; i < k; i++) {
				if (arr[k] > arr[i]) {
					length[k] = max(length[k], length[i] + 1);
				}
		}
	}
	*/
	int Max=0;
	for (int i = 0; i < N; i++) {
		Max = max(Max, length[i]);
	}
	cout << "���� �κ� ������ ���̴� " << Max << "�Դϴ�" << endl;
}