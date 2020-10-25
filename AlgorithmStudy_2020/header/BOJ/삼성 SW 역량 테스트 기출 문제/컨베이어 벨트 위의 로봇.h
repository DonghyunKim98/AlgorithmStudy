#include <bits/stdc++.h>
//20055�� ����
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100 + 1;
int N, K;
vector<int> vc(2 * MAX + 1);
bool visit[2 * MAX + 1];
queue<int> robot;

bool process() { 
	//1������
	//��Ʈ �ű��
	int temp = vc[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		vc[i] = vc[i - 1];
	}
	vc[1] = temp;
	int size = robot.size();
	for (int i = 0; i < size; i++) {
		int cur = robot.front();
		robot.pop();
		visit[cur] = false;
		if (cur + 1 != N) {
			visit[cur + 1] = true;
			robot.push(cur + 1);
		}
	}

	//2������
	//�κ� �����̱�
	size = robot.size();
	for (int i = 0; i < size; i++) {
		int cur = robot.front();
		robot.pop();
		//�������� �����̱� ���ؼ�, ���� �����̾� ��Ʈ�� �������� 0�� �ƴϰ� ��Ʈ���� �κ��� �������
		if (vc[cur + 1] != 0 && visit[cur + 1] == false) {
			visit[cur] = false;
			vc[cur + 1]--;
			if (cur + 1 != N) {
				visit[cur + 1] = true;
				robot.push(cur + 1);
			}
		}
		else robot.push(cur);
	}
	
	//3������
	//�κ� �ø���
	if (vc[1] != 0 && visit[1] == false) {
		visit[1] = true;
		vc[1]--;
		robot.push(1);
	}

	//4������
	//������ Ȯ��
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (vc[i] == 0) cnt++;
	}
	return cnt < K;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> vc[i];
	}
	memset(visit, false, sizeof(visit));
	int cnt = 1;
	while (1) {
		if (!process()) break;
		cnt++;
	}
	cout << cnt;
}

/*
	1. �ʹ� "�־��� �������" �� �����ҷ��� �� �������� ����� �ڷᱸ���� ������� �ߴ�.
	   �ǻ��� ť�� ���� �Ǵµ� ���̴�.
	2. �� ����, "��Ʈ�� ������" �� "��Ʈ ���� �κ��� �ִ��� ����" �� �ʹ� ��ĥ���� �ߴ�.
	   �ǻ��� �׳� �迭 2�� ����� �Ǵµ� ���̴�.

	������ �ٽ� �����ϸ�, ������ Ǯ����µ� �ʿ��� ������ 4�����̴�.
	1) ��Ʈ�� ������
	2) ��Ʈ���� �峭�� ����
	3) �峭���� ��ġ
	4) �峭���� �� ����

	�� 4������ ���� �ѹ��� ó�����ص� �ȴ�. �������� �����ص� ���� �� ����.
*/