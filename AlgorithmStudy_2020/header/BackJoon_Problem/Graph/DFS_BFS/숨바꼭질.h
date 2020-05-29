#include <bits/stdc++.h>

//1697������
//https://wkdtjsgur100.github.io/algo-1697/ ����
using namespace std;
bool visited[100000] = { false, };
queue<pair<int, int>> q;
int N, K;

void BFS() {
	q.push(pair<int, int>(N, 0));
	while (!q.empty()) {
        int pos = q.front().first;
        int depth = q.front().second;

        if (pos == K)
            break;

        q.pop();

        visited[pos] = true;

        if (pos - 1 >= 0 && !visited[pos - 1])
            q.push(pair<int, int>(pos - 1, depth + 1));
        if (pos + 1 <= 100000 && !visited[pos + 1])
            q.push(pair<int, int>(pos + 1, depth + 1));
        if (pos * 2 <= 100000 && !visited[pos * 2])
            q.push(pair<int, int>(pos * 2, depth + 1));
	}
}

void HideandSeek(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
    BFS();
    cout << q.front().second << endl;
}

/*
    �����ؾ� �� ��
    1) Ư���� ���ǵ��� �� �����غ��� (��ġ DFS�� �������� ������� �� ���簢�� ������ ������ 
    �ȵǴ� ��ó��)
    -> ���⼱ 2�� ���ϰų� �� ���� 100000�� ��� ���� �ִ�!
    2) �迭 3���� 100001������ �����ϸ�, �޸𸮰� �ʹ� ũ��. ���� ť�� pair���·� ����
    3) ������ ��� ��尡 ���� ���� �̹� �˰� �����Ƿ� ���� ��������Ʈ �ۼ� X
    4) �߰��� K�� �� ������ ����!! break�� �ɾ �ٷ� �ű⼭ depth�� ���!
*/