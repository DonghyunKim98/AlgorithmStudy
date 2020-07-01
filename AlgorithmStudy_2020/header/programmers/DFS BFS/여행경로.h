#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
vector<int> adj[MAX];
vector<string> answer;
map<string, int> mp;
bool visited[MAX];

void DFS(int current_node) {
    if (visited[current_node]) return;
    visited[current_node] = true;
    answer.push_back()
}

vector<string> solution(vector<vector<string>> tickets) {
    int index = 0;
    int start_node = -1;
    for (int i = 0; i < tickets.size(); i++) {
        if (mp.count(tickets[i][0]) == 0) {
            mp.insert(make_pair(tickets[i][0], index));
            index++;
        }
        if (mp.count(tickets[i][1]) == 0) {
            mp.insert(make_pair(tickets[i][1], index));
            index++;
        }
        if (tickets[i][0] == "ICN") start_node = mp[tickets[i][0]];
        if (tickets[i][1] == "ICN") start_node = mp[tickets[i][1]];
        int current_node = mp[tickets[i][0]];
        int next_node = mp[tickets[i][1]];
        //단방향 노드.
        adj[current_node].push_back(next_node);
    }
    return answer;
}

/*
    DFS를 할건데 어떻게?? 정렬해서!
*/