#include <bits/stdc++.h>
using namespace std;
double input_A, input_B, input_target;
char current;

int BFS(int input, int target) {
	int ans = 0;
	int cnt_visited[146001] = { 0, };
	bool visited[146001] = { false };
	queue<int> up_q, down_q;
	up_q.push(input); visited[input] = true;
	while (!up_q.empty()) {
		int current = up_q.front(); up_q.pop();
		//target�� ��ġ�ҽ� while���� ��������
		if (current == target) {
			ans = cnt_visited[current]; break;
		}
		//6�� �ѱ��� 7�� return
		if (cnt_visited[current] > 6) {
			ans = 7; break;
		}

		int up = current + 20;
		if (up > 146000) up = 144000;
		
		if (!visited[up]) {
			visited[up] = true; cnt_visited[up] = cnt_visited[current] + 1;
			up_q.push(up);
		}
	}
	memset(visited, false, sizeof(visited));
	memset(cnt_visited, 0, sizeof(cnt_visited));
	down_q.push(input);	visited[input] = true;
	while (!down_q.empty()) {
		int current = down_q.front(); down_q.pop();
		//target�� ��ġ�ҽ� while���� ��������
		if (current == target) {
			ans =min(ans,cnt_visited[current]); break;
		}
		//6�� �ѱ��� 7�� return
		if (cnt_visited[current] > 6) {
			ans = min(ans,7); break;
		}
		int down = current - 20;
		if (down < 144000) down = 146000;
		if (!visited[down]) {
			visited[down] = true; cnt_visited[down] = cnt_visited[current] + 1;
			down_q.push(down);
		}
	}
	return ans;
}


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> input_A >> input_B >> current >> input_target;
		int A = (input_A) * 1000, B = (input_B) * 1000, target = (input_target) * 1000;
		int A_ans = BFS(A,target), B_ans = BFS(B,target);
		//A���� B�� B���� A�� �ٲٴ� Ƚ�� count
		current == 'A' ? B_ans++ : A_ans++;

		cout << min(6, min(A_ans, B_ans)) << '\n';
	}
}

/*
	�ִ� 6�� -> ���� Ű�е带 ������ �ϱ� ����
	���� 6�� �̳��� ó���� �� �ִ����� Ȯ���Ѵ�.


	�˰��� ����
	-> BFS : "�ּ�"�̱� �����̴�. (�̺�Ž���� �����ϱ� ��ƴٴ°� ������ ���δ�)
	-> �׷����� ���ø��� ���ߴ� ������ �׷��� ó�� ���������°� �ƴ� ���� �� 1���� ���⸸ �����߱� ����
	-> BFS�� �����ϸ� logic�� �ξ� ����
*/