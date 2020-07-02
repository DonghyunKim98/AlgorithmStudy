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
		//�湮�� ����� string�� push
		answer.push_back(mp2[current_node]);
		//�� �̻� �� node���� �湮�� node�� ���� ���.
		if (adj[current_node].empty()) {
			//��� Ƽ���� �� ���� ���� ���
			if (cnt == total)
				return true;
			//��� Ƽ���� �� ���� �ƴѵ� ���̻� �湮�� node�� ���� ��� -> �ٸ� ����� ���� ã�ƾ� ��.
			else return false;
		}
		pair<int, string> temp = adj[current_node][0];
		//�������� �湮�� ��忡 �ش��ϴ� ���� ����. 
		adj[current_node].erase(adj[current_node].begin());
		//true�� ��ȯ�ߴٸ� stop.
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
		//�ܹ��� ���.
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

=> ���� Ǯ�� (�ٵ� ���� �������� ���� �����µ� �޸� �ʰ��� ��� �Ф�)
*/

/*
	DFS�� �Ұǵ� ���?? �����ؼ�!

	�˰��� ����Ʈ
	=> �̾����� �ʴ� ��츦 ��� Ž������?
*/