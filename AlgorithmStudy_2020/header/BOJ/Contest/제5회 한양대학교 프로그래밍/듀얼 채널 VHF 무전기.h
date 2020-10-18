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
		//target과 일치할시 while문을 빠져나옴
		if (current == target) {
			ans = cnt_visited[current]; break;
		}
		//6을 넘길경우 7을 return
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
		//target과 일치할시 while문을 빠져나옴
		if (current == target) {
			ans =min(ans,cnt_visited[current]); break;
		}
		//6을 넘길경우 7을 return
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
		//A에서 B로 B에서 A로 바꾸는 횟수 count
		current == 'A' ? B_ans++ : A_ans++;

		cout << min(6, min(A_ans, B_ans)) << '\n';
	}
}

/*
	최대 6번 -> 숫자 키패드를 눌러야 하기 때문
	따라서 6번 이내로 처리할 수 있는지를 확인한다.


	알고리즘 설명
	-> BFS : "최소"이기 때문이다. (이분탐색을 적용하긴 어렵다는건 딱봐도 보인다)
	-> 그렇지만 떠올리지 못했던 이유는 그래프 처럼 퍼져나가는게 아닌 오직 딱 1개의 방향만 존재했기 때문
	-> BFS로 구현하면 logic이 훨씬 쉽다
*/