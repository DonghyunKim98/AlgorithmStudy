#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
vector<pair<int, string>> adj[MAX];
vector<string> answer;
map<string, int> mp;
map<int, string> mp2;
int total;
bool comp(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

bool DFS(int current_node, int cnt) {
	while (true) {
		//방문한 노드의 string을 push
		answer.push_back(mp2[current_node]);
		//더 이상 이 node에서 방문할 node가 없을 경우.
		if (adj[current_node].empty()) {
			//모든 티켓을 다 돌고 없는 경우
			if (cnt == total)
				return true;
			//모든 티켓을 다 돈게 아닌데 더이상 방문할 node가 없는 경우 -> 다른 경우의 수를 찾아야 함.
			else return false;
		}
		pair<int, string> temp = adj[current_node][0];
		//다음으로 방문할 노드에 해당하는 간선 삭제. 
		adj[current_node].erase(adj[current_node].begin());
		//true를 반환했다면 stop.
		if (DFS(temp.first, cnt + 1))
			break;
		//false->backTracking
		else {
			answer.erase(answer.end() - 1);
			adj[current_node].push_back(temp);
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	int index = 0;
	int start_node = -1;
	total = tickets.size();
	for (int i = 0; i < tickets.size(); i++) {
		if (mp.count(tickets[i][0]) == 0) {
			mp.insert(make_pair(tickets[i][0], index));
			mp2.insert(make_pair(index, tickets[i][0]));
			index++;
		}
		if (mp.count(tickets[i][1]) == 0) {
			mp.insert(make_pair(tickets[i][1], index));
			mp2.insert(make_pair(index, tickets[i][1]));
			index++;
		}
		if (tickets[i][0] == "ICN") start_node = mp[tickets[i][0]];
		if (tickets[i][1] == "ICN") start_node = mp[tickets[i][1]];
		int current_node = mp[tickets[i][0]];
		int next_node = mp[tickets[i][1]];
		//단방향 노드.
		adj[current_node].push_back(make_pair(next_node, tickets[i][1]));
	}

	//sorting
	for (int i = 0; i < mp.size(); i++)
		sort(adj[i].begin(), adj[i].end(), comp);

	//DFS
	DFS(start_node, 0);
	return answer;
}

/*
bool dfs(string here, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& tmp, vector<string>& answer, int cnt) {
	tmp.push_back(here);
	if (cnt == tickets.size()) {
		answer = tmp;
		return true;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == here and !visited[i]) {
			visited[i] = true;
			if (dfs(tickets[i][1], tickets, visited, tmp, answer, cnt + 1)) return true;
			visited[i] = false;
		}
	}
	tmp.pop_back();
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visited(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	vector<string> tmp;
	dfs("ICN", tickets, visited, tmp, answer, 0);
	return answer;
}

=> 정답 풀이 (근데 내거 돌려봐도 답은 나오는데 메모리 초과가 뜬다 ㅠㅠ)
*/

/*
	DFS를 할건데 어떻게?? 정렬해서!

	알고리즘 포인트
	=> 이어지지 않는 경우를 어떻게 탐색하지?
*/