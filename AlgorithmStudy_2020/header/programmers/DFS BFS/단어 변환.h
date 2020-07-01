#include <bits/stdc++.h>
using namespace std;
const int MAX = 50+1;
vector<int> vc[MAX];
int begin_node, target_node = -1;
int answer = -1;

int solution(string begin, string target, vector<string> words) {
	//begin_node ����
	for (int i = 0; i < words.size(); i++) {
		int is_differ = 0;
		for (int k = 0; k < words[0].length(); k++) {
			if (begin[k] != words[i][k]) is_differ++;
		}
		//�� �� ���ڸ� �ٸ� ������
		if (is_differ == 1) vc[0].push_back(i+1);
	}

	//words�� �ִ� ���� index�� 1���� �������� ó��
	for (int i = 1; i <= words.size(); i++) {
		int original_index1 = i - 1;
		if (target == words[original_index1]) target_node = i;
		for (int j = i + 1; j <= words.size(); j++) {
			int original_index2 = j - 1;
			int is_differ = 0;
			for (int k = 0; k < words[0].length(); k++) {
				if (words[original_index1][k] != words[original_index2][k]) is_differ++;
			}
			//�� �� ���ڸ� �ٸ� ������
			if (is_differ == 1) {
				vc[i].push_back(j);
				vc[j].push_back(i);
			}
		}
	}

	//BFS
	bool visited[MAX];
	fill_n(visited, MAX, false);
	int Distance[MAX];
	queue<int> q;
	//base case ����
	visited[0] = true;
	Distance[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int current_node = q.front();
		int current_distance = Distance[current_node];
		q.pop();
		for (auto u : vc[current_node]) {
			if (visited[u]) continue;
			visited[u] = true;
			Distance[u] = current_distance + 1;
			if (u == target_node) answer = Distance[u];
			q.push(u);
		}
	}

	//���ʿ� target Node�� ���ų� �湮���� ����->return 0;
	if (answer == -1) return 0;
	else return answer;
}

/*
   O(n^2) ���� adj�� push�ϰ�
   O(n+m) ���� DFS.
*/