#include <bits/stdc++.h>
//1520�� ����
//https://wootool.tistory.com/83 ����
using namespace std;
const int MAX = 500;
int grid[MAX][MAX];
int visited[MAX][MAX];
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dfs(int xpos, int ypos) {
	if (xpos == N-1 && ypos == M-1) 
		return 1;

	//������ �湮�ߴٸ� ������ ���� ��ȯ.
	if (visited[ypos][xpos]!=-1) return visited[ypos][xpos];
	visited[ypos][xpos] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = xpos + dx[k];
		int ny = ypos + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			if (grid[ny][nx] < grid[ypos][xpos]) 
				//�����ش� -> �̰����� �ѹ� �湮�� ���� ��湮���� �ʰ� ȿ�������� ��� ����� ���� ���� �� ����
				visited[ypos][xpos]+=dfs(nx, ny);
	}
	return visited[ypos][xpos];
}
void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			cin >> grid[i][j];
	memset(visited, -1, sizeof(visited));
	cout<<dfs(0, 0);
}

/*
	�˰��� ����Ʈ
	1. �İ��� ���� ���������� ä������ ���� �Ʒ�������.
	2. �� �μ��� �̵��ϱ� ó��, �̹� �湮�� ���� �� �湮�� 
	=> �� �μ��� �̵��ϱ�� ������ �ν��°� �� �ν��°��� Ȯ���ϸ� �Ʊ⿡ 3���� �迭�� ����
	=> �̰� ����� ���� �� ������, Ư�� �������� �����ϰ� '�� ���� ��δ� ������ ���⿡' �ܼ��� �����ָ� ��.
	=> �� �μ��� �̵��ϱ�� Ư�� �������� �����Ѵٰ� �ص� �� ���� ��ΰ� ������ �� ������ (������ ���� �ν����� �� �ν����� ����) �𸣱⿡ 3���� �迭�� �����Ͼ� ����.

	3. �ܼ��� DFS�� �ð��ʰ��� ����.
*/