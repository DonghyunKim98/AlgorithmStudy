#include <bits/stdc++.h>
//12100�� ����
using namespace std;
const int MAX = 20;
int N, ans = 0;
int MAP[MAX][MAX];

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans < MAP[i][j] ? ans = MAP[i][j] : ans = ans;
		return;
	}
	int temp[MAX][MAX];
	std::copy(&MAP[0][0], &MAP[0][0] + (MAX) * (MAX), &temp[0][0]);
	for (int k = 0; k < 4; k++) {
		int temp_val;
		//���� �б�
		if (k == 0) {
			for (int xpos = 0; xpos < N; xpos++) {
				vector<int> vc;
				temp_val = MAP[0][xpos];
				for (int i = 1; i < N; i++) {
					//������� �������� -> �׳� pass
					if (MAP[i][xpos] == 0) {}
					//temp_val�� 0�ε� ����� ��������
					else if (temp_val == 0 && MAP[i][xpos] != 0) {
						temp_val = MAP[i][xpos];
					}
					//temp_val�� ���� ����� ��������
					else if (MAP[i][xpos] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val�� ���� ���� ����� ��������
					else if (MAP[i][xpos] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[i][xpos];
					}
					//���� ����ó��
					if (i == N - 1 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = 0; i < N; i++) {
					if (i < vc.size()) {
						MAP[i][xpos] = vc[i];
					}
					else MAP[i][xpos] = 0;
				}
			}
		}
		//�Ʒ��� �б�
		else if (k == 1) {
			for (int xpos = 0; xpos < N; xpos++) {
				vector<int> vc;
				temp_val = MAP[N - 1][xpos];
				for (int i = N - 2; i >= 0; i--) {
					//������� �������� -> �׳� pass
					if (MAP[i][xpos] == 0) {}
					//temp_val�� 0�ε� ����� ��������
					else if (temp_val == 0 && MAP[i][xpos] != 0) {
						temp_val = MAP[i][xpos];
					}
					//temp_val�� ���� ����� ��������
					else if (MAP[i][xpos] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val�� ���� ���� ����� ��������
					else if (MAP[i][xpos] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[i][xpos];
					}
					//���� ����ó��
					if (i == 0 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = N - 1; i >= 0; i--) {
					if (i < vc.size()) {
						MAP[i][xpos] = vc[i];
					}
					else MAP[i][xpos] = 0;
				}
			}
		}
		//�������� �б�
		else if (k == 2) {
			for (int ypos = 0; ypos < N; ypos++) {
				vector<int> vc;
				temp_val = MAP[ypos][0];
				for (int i = 1; i < N; i++) {
					//������� �������� -> �׳� pass
					if (MAP[ypos][i] == 0) {  }
					//temp_val�� 0�ε� ����� ��������
					else if (temp_val == 0 && MAP[ypos][i] != 0) {
						temp_val = MAP[ypos][i];
					}
					//temp_val�� ���� ����� ��������
					else if (MAP[ypos][i] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val�� ���� ���� ����� ��������
					else if (MAP[ypos][i] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[ypos][i];
					}
					//���� ����ó��
					if (i == N - 1 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = 0; i < N; i++) {
					if (i < vc.size()) {
						MAP[ypos][i] = vc[i];
					}
					else MAP[ypos][i] = 0;
				}
			}
		}
		//���������� �б�
		else {
			for (int ypos = 0; ypos < N; ypos++) {
				vector<int> vc;
				temp_val = MAP[ypos][N - 1];
				for (int i = N - 2; i >= 0; i--) {
					//������� �������� -> �׳� pass
					if (MAP[ypos][i] == 0) {}
					//temp_val�� 0�ε� ����� ��������
					else if (temp_val == 0 && MAP[ypos][i] != 0) {
						temp_val = MAP[ypos][i];
					}
					//temp_val�� ���� ����� ��������
					else if (MAP[ypos][i] == temp_val) {
						vc.push_back(temp_val * 2);
						temp_val = 0;
					}
					//temp_val�� ���� ���� ����� ��������
					else if (MAP[ypos][i] != temp_val) {
						vc.push_back(temp_val);
						temp_val = MAP[ypos][i];
					}
					//���� ����ó��
					if (i == 0 && temp_val != 0) {
						vc.push_back(temp_val);
					}
				}
				if (N == 1) vc.push_back(temp_val);
				for (int i = N - 1; i >= 0; i--) {
					if (i < vc.size()) {
						MAP[ypos][i] = vc[i];
					}
					else MAP[ypos][i] = 0;
				}
			}
		}
		DFS(cnt + 1);
		std::copy(&temp[0][0], &temp[0][0] + (MAX) * (MAX), &MAP[0][0]);
	}
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> MAP[i][j];
	DFS(0);
	cout << ans;
}