#include <bits/stdc++.h>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
int solution(vector<int> arrows) {
	int answer = 0;
	//{key,value}
	//{x,y} 에 대해서 얼마나 많이 방문했는지 -> O(1)에 찾을 수 있으니깐
	map <pair<int, int>, int>  vertex_visited;
	//{x1,y1} -> {x2,y2} 하는 간선이 얼마나 많이 쓰였는지 
	map <pair<pair<int, int>, pair<int, int>>, int> edge_visited;

	//시작 지점
	int x = 0, y = 0;
	vertex_visited[{x, y}] = 1;

	for (int i = 0; i < arrows.size(); i++) {
		//X 자 교차형태도 세야하므로, 2배 => 1/2 만큼 변의 길이로 교차될 수 있음.
		//2배로 늘리면 무조건 정수 격자점을 통과
		for (int j = 0; j < 2; j++) {
			int nXpos = x + dx[arrows[i]];
			int nYpos = y + dy[arrows[i]];
			//격자점을 이전에 한번 방문했다면
			if (vertex_visited[{nXpos, nYpos}] == 1)
				//지금 이 경로로 방문한 것이 아니라면.
				if (edge_visited[{ {x, y}, { nXpos,nYpos }}] == 0 || edge_visited[{ {nXpos, nYpos}, { x,y }}] == 0) answer++; //정답을 하나 늘려줌
			//체크
			vertex_visited[{nXpos, nYpos}] = 1;

			//edge 체크
			edge_visited[{ {nXpos, nYpos}, { x, y }}] = 1;
			edge_visited[{ {x, y}, { nXpos, nYpos }}] = 1;

			x = nXpos;
			y = nYpos;
		}
	}
	return answer;
}

/*
	Line 21~23 추가 해설
	- 이전에 방문했다고 또 방문하다고 반드시 도형을 보장할 수 있는가??
	=> YES!! '닫힌 도형'이 되기 때문이다.


*/