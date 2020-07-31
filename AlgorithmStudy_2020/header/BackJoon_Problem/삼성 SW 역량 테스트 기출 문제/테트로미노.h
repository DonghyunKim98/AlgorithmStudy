#include <bits/stdc++.h>
//14500�� ����
using namespace std;
const int MAX = 500 + 1;
int arr[MAX][MAX];
int N, M;

void solution() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	/*
		����
		����
	*/
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			answer = max(answer, temp);
		}
	}
	/*
		������ or ������ or ������ or ��������
		��          ��		  ��
	*/
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int base = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			int temp1 = base + arr[i + 1][j];
			int temp2 = base + arr[i + 1][j + 1];
			int temp3 = base + arr[i + 1][j + 2];
			int temp4 = (j == M - 2) ? 0 : base + arr[i][j + 3];
			answer = max(answer, max(max(temp1, temp2), max(temp3, temp4)));
		}
	}
	/*
		��         ��           ��
		������ or ������ or  ������
	*/
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M - 2; j++) {
			int base = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			int temp1 = base + arr[i - 1][j];
			int temp2 = base + arr[i - 1][j + 1];
			int temp3 = base + arr[i - 1][j + 2];
			answer = max(answer, max(max(temp1, temp2), temp3));
		}
	}
	/*
		����    ��      ��      ��
		��  or  ���� or ��   or ��
		��	    ��      ����    ��
								��
	*/
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int base = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
			int temp1 = base + arr[i][j + 1];
			int temp2 = base + arr[i + 1][j + 1];
			int temp3 = base + arr[i + 2][j + 1];
			int temp4 = (i == N - 2) ? 0 : base + arr[i + 3][j];
			answer = max(answer, max(max(temp1, temp2), max(temp3, temp4)));
		}
	}
	/*
		���� or   ��  or   ��
		  ��    ����       ��
		  ��      ��     ����

	*/
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 2; j <= M; j++) {
			int base = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
			int temp1 = base + arr[i][j - 1];
			int temp2 = base + arr[i + 1][j - 1];
			int temp3 = base + arr[i + 2][j - 1];
			int temp4 = (j == M) ? base + arr[i + 3][j] : 0;
			answer = max(answer, max(max(temp1, temp2), max(temp3, temp4)));
		}
	}
	/*
		��         ��
		����  or ����
		  ��     ��
	*/

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			int base = arr[i][j] + arr[i][j + 1];
			int temp1 = base + arr[i - 1][j] + arr[i + 1][j + 1];
			int temp2 = base + arr[i + 1][j] + arr[i - 1][j + 1];
			answer = max(answer, max(temp1, temp2));
		}
	}


	/*
		����          ����
		  ����  or  ����
	*/
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 2; j <= M - 1; j++) {
			int base = arr[i][j] + arr[i + 1][j];
			int temp1 = base + arr[i][j - 1] + arr[i + 1][j + 1];
			int temp2 = base + arr[i][j + 1] + arr[i + 1][j - 1];
			answer = max(answer, max(temp1, temp2));
		}
	}
	cout << answer;
}