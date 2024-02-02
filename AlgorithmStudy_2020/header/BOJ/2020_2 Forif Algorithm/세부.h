#include <bits/stdc++.h>
// 13905번 문제
using namespace std;
const int MAX = 300000 + 1;
typedef pair<int, int> pii;
vector<pii> adj[MAX];
int N, M, s, e;
bool visited[MAX];

bool BFS(int mid)
{
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		if (curNode == e)
			return true;
		for (auto u : adj[curNode])
		{
			int nextNode = u.first;
			int cost = u.second;
			if (visited[nextNode])
				continue;
			// 최소치보다 더 나간다면
			if (cost >= mid)
			{
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}
	}
	// 발견하지 못했으면
	return false;
}

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> s >> e;
	int MAX = 0;
	// 무방향 가중 그래프 집어넣기
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		adj[node1].push_back({node2, weight});
		adj[node2].push_back({node1, weight});
		MAX = max(weight, MAX);
	}

	int begin = 0, end = MAX;
	int ans = 0;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		// mid 값을 최소한으로 삼았을때 통과가 되면
		if (BFS(mid))
		{
			ans = mid;
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << ans;
}
typedef vector<int> vci;
vector<vci> adj2;
int parent[MAX];

int find(int idx)
{
	// 자기 자신이 최상위 노드라면 자기 자신 return
	if (parent[idx] == idx)
		return idx;
	// 아니라면 최상위 노드를 찾아서 return
	else
		return parent[idx] = find(parent[idx]);
}

bool cmp(vci &a, vci &b)
{
	return a[2] > b[2];
}

// 스패닝 트리를 이용하는 문제
void solution2()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> s >> e;
	// 무방향 가중 그래프 집어넣기
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		vci temp = {node1, node2, weight};
		adj2.push_back(temp);
	}
	// 가중치가 높은 순서대로 정렬
	sort(adj2.begin(), adj2.end(), cmp);

	// 일단 자기자신의 부모는 자기자신
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		int current = find(adj2[i][0]);
		int next = find(adj2[i][1]);
		int cost = adj2[i][2];

		// 연결 여부 확인
		if (current != next)
		{
			parent[next] = current;
			// 만약 이번 걸로 start와 end가 이어졌다면
			// 이번 cost가 연결짓는 최저 코스트 (내림차순으로 sorting했기 때문)
			if (find(s) == find(e))
			{
				ans = cost;
				break;
			}
		}
	}
	cout << ans;
}

vector<pii> MST[MAX];
// 스패닝 트리 + BFS
void solution3()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> s >> e;
	// 무방향 가중 그래프 집어넣기
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		vci temp = {node1, node2, weight};
		adj2.push_back(temp);
	}
	// 가중치가 높은 순서대로 정렬
	sort(adj2.begin(), adj2.end(), cmp);

	// 일단 자기자신의 부모는 자기자신
	for (int i = 1; i <= M; i++)
		parent[i] = i;

	for (int i = 0; i < adj2.size(); i++)
	{
		int current = find(adj2[i][0]);
		int next = find(adj2[i][1]);
		int cost = adj2[i][2];

		// 연결 여부 확인
		if (current != next)
		{
			parent[next] = current;
			MST[adj[i][0]].push_back({adj[i][1], cost});
			MST[adj[i][1]].push_back({adj[i][0], cost});
		}
	}

	// 스패닝 트리 탐색
	queue<pii> q;
	memset(visited, 0, sizeof(visited));
	q.push({s, INT_MAX});
	visited[s] = true;
	int ans = 0;
	while (!q.empty())
	{
		int curNode = q.front().first;
		int curMAXCost = q.front().second;
		q.pop();
		if (curNode == e)
		{
			ans = curMAXCost;
			break;
		}
		for (auto u : MST[curNode])
		{
			if (visited[u.first])
				continue;
			visited[u.first] = true;
			q.push({u.first, min(curMAXCost, u.second)});
		}
	}
	cout << ans;
}
/*
	일단 떠오른 생각
	1. Maximum Spanning Tree를 만든다??
		=> 크루스칼 알고리즘을 역이용해서?
	2. BFS로 탐방을 하는데, 무조건 더 크게 탐방을 해야함
		=> 근데 이러면 빙빙돌텐데
		=> 사이클을 형성하지 않는 선에서 돌아야함
	다 안됨
	=> 그러면 BFS + 이분탐색 logic은 가능할려나


	결국 solution 3가지
	1) Parmetric Search + BFS
	2) MST 응용
	3) MST + BFS
*/