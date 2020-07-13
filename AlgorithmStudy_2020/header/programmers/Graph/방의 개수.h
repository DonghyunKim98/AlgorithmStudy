#include <bits/stdc++.h>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
int solution(vector<int> arrows) {
	int answer = 0;
	//{key,value}
	//{x,y} �� ���ؼ� �󸶳� ���� �湮�ߴ��� -> O(1)�� ã�� �� �����ϱ�
	map <pair<int, int>, int>  vertex_visited;
	//{x1,y1} -> {x2,y2} �ϴ� ������ �󸶳� ���� �������� 
	map <pair<pair<int, int>, pair<int, int>>, int> edge_visited;

	//���� ����
	int x = 0, y = 0;
	vertex_visited[{x, y}] = 1;

	for (int i = 0; i < arrows.size(); i++) {
		//X �� �������µ� �����ϹǷ�, 2�� => 1/2 ��ŭ ���� ���̷� ������ �� ����.
		//2��� �ø��� ������ ���� �������� ���
		for (int j = 0; j < 2; j++) {
			int nXpos = x + dx[arrows[i]];
			int nYpos = y + dy[arrows[i]];
			//�������� ������ �ѹ� �湮�ߴٸ�
			if (vertex_visited[{nXpos, nYpos}] == 1)
				//���� �� ��η� �湮�� ���� �ƴ϶��.
				if (edge_visited[{ {x, y}, { nXpos,nYpos }}] == 0 || edge_visited[{ {nXpos, nYpos}, { x,y }}] == 0) answer++; //������ �ϳ� �÷���
			//üũ
			vertex_visited[{nXpos, nYpos}] = 1;

			//edge üũ
			edge_visited[{ {nXpos, nYpos}, { x, y }}] = 1;
			edge_visited[{ {x, y}, { nXpos, nYpos }}] = 1;

			x = nXpos;
			y = nYpos;
		}
	}
	return answer;
}

/*
	Line 21~23 �߰� �ؼ�
	- ������ �湮�ߴٰ� �� �湮�ϴٰ� �ݵ�� ������ ������ �� �ִ°�??
	=> YES!! '���� ����'�� �Ǳ� �����̴�.


*/