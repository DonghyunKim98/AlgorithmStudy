#include <bits/stdc++.h>
//9466�� ����
//https://lmcoa15.tistory.com/51 ����
using namespace std;
const int MAX = 100000 + 1;
vector<int> student; //�л��� ����Ű�� �ٸ� �л� ��ȣ
vector<int> first_student; //ù ��°�� dfs�� ������ �л� ��ȣ
vector<int> visited; //�湮 ����
int DFS(int start, int current, int cnt) {
	//�� �湮�Ѵٸ�
	if (visited[current]) {
		//ù ��°�� dfs�� ������ �л��� �´���, ����Ŭ�� �´���
		//�� ó������ ����Ŭ�� ã��������
		if (first_student[current] != start) return 0;

		//����Ŭ�� �ش�Ǵ� �л� ��
		return cnt - visited[current];
	}
	first_student[current] = start;
	visited[current] = cnt;
	return DFS(start, student[current], cnt + 1);

}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T,N;
	cin >> T;
	while (T--) {
		cin >> N;
		student = vector<int>(N + 1, 0);
		first_student = vector<int>(N + 1, 0);
		visited = vector<int>(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> student[i];
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				ans += DFS(i, i, 1);
			}
		}
		cout << N - ans << '\n';
	}
}

/*
	����Ŭ�� �̷�°�?? �� ���� ��.

	�˰��� ����Ʈ
	1. ������ ã�� ����Ŭ�� ��� ������ ���ΰ�?? �� ���� ����.
	   ó���� ���Ϳ� �����ؼ� ����Ŭ�� ã�� ���Ŀ� �ִ� ������ �����ߴµ�, ���ڷ� �ѱ�⵵ ��ư� �����ϴ� �͵� �����
	   => �̸� �ذ��ϱ� ���ؼ� 'DFS�� ������ ��带 �����Ѵ�!' ��� ����
	   => �׷� ���� ����Ŭ�� 2�� ã���� ���� ���̴ϱ�.
	   => ���� �� ����� �޸𸮰� ���� ��ƸԱ��Ѵ�.
*/