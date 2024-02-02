#include <bits/stdc++.h>
// 13905�� ����
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
			// �ּ�ġ���� �� �����ٸ�
			if (cost >= mid)
			{
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}
	}
	// �߰����� ��������
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
	// ������ ���� �׷��� ����ֱ�
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
		// mid ���� �ּ������� ������� ����� �Ǹ�
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
	// �ڱ� �ڽ��� �ֻ��� ����� �ڱ� �ڽ� return
	if (parent[idx] == idx)
		return idx;
	// �ƴ϶�� �ֻ��� ��带 ã�Ƽ� return
	else
		return parent[idx] = find(parent[idx]);
}

bool cmp(vci &a, vci &b)
{
	return a[2] > b[2];
}

// ���д� Ʈ���� �̿��ϴ� ����
void solution2()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> s >> e;
	// ������ ���� �׷��� ����ֱ�
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		vci temp = {node1, node2, weight};
		adj2.push_back(temp);
	}
	// ����ġ�� ���� ������� ����
	sort(adj2.begin(), adj2.end(), cmp);

	// �ϴ� �ڱ��ڽ��� �θ�� �ڱ��ڽ�
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		int current = find(adj2[i][0]);
		int next = find(adj2[i][1]);
		int cost = adj2[i][2];

		// ���� ���� Ȯ��
		if (current != next)
		{
			parent[next] = current;
			// ���� �̹� �ɷ� start�� end�� �̾����ٸ�
			// �̹� cost�� �������� ���� �ڽ�Ʈ (������������ sorting�߱� ����)
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
// ���д� Ʈ�� + BFS
void solution3()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> s >> e;
	// ������ ���� �׷��� ����ֱ�
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		vci temp = {node1, node2, weight};
		adj2.push_back(temp);
	}
	// ����ġ�� ���� ������� ����
	sort(adj2.begin(), adj2.end(), cmp);

	// �ϴ� �ڱ��ڽ��� �θ�� �ڱ��ڽ�
	for (int i = 1; i <= M; i++)
		parent[i] = i;

	for (int i = 0; i < adj2.size(); i++)
	{
		int current = find(adj2[i][0]);
		int next = find(adj2[i][1]);
		int cost = adj2[i][2];

		// ���� ���� Ȯ��
		if (current != next)
		{
			parent[next] = current;
			MST[adj[i][0]].push_back({adj[i][1], cost});
			MST[adj[i][1]].push_back({adj[i][0], cost});
		}
	}

	// ���д� Ʈ�� Ž��
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
	�ϴ� ������ ����
	1. Maximum Spanning Tree�� �����??
		=> ũ�罺Į �˰����� ���̿��ؼ�?
	2. BFS�� Ž���� �ϴµ�, ������ �� ũ�� Ž���� �ؾ���
		=> �ٵ� �̷��� �������ٵ�
		=> ����Ŭ�� �������� �ʴ� ������ ���ƾ���
	�� �ȵ�
	=> �׷��� BFS + �̺�Ž�� logic�� �����ҷ���


	�ᱹ solution 3����
	1) Parmetric Search + BFS
	2) MST ����
	3) MST + BFS
*/