#include <bits/stdc++.h>
//1966번 문제
using namespace std;

void PrinterQueue() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T > 0) {
		int N, M;
		cin >> N >> M;
		//<중요도,원래index>
		vector<pair<int, int>> vc;
		for (int i = 0; i < N; i++) {
			int majority;
			cin >> majority;
			vc.push_back(make_pair(majority, i));
		}
		int count = 0;
		while (true) {
			
			//지금 맨 앞에 있는 원소의 majority가 제일 높은지 확인
			int current_majority = vc.at(0).first;
			bool is_top = true;
			for (int i = 1; i < vc.size(); i++) {
				//만약 뒤에 더 큰게 있음
				if (vc.at(i).first > current_majority) {
					is_top = false;
					//맨 앞에 있는 원소를 맨 뒤로 보내고 맨 앞에 있는 친구 지움
					vc.push_back(vc.at(0));
					vc.erase(vc.begin());
					break;
				}
			}
			//지금 맨 앞에 있는 애가 확실하게 제일 우선순위가 높다!! =>출력
			if (is_top) {
				count++;
				if (vc.at(0).second == M) {
					cout << count << '\n';
					break;
				}
				vc.erase(vc.begin());
			}
		}
		T--;
	}

}

/*
	우선순위 큐?? => 그렇게 되면 먼저 들어온 순으로 수행이 되야 함.
	큐 => 모든 곳에 접근이 안돼.
	백터로 모든곳에 접근하자!! -> 지금 N의 최대값이 50이기때문에 시간초과가 안남.

	<우선순위 큐 이용 풀이>
	->http://melonicedlatte.com/algorithm/2018/02/18/230705.html
	-> 우선순위 큐'만'을 사용했을땐 index가 높은 순으로 정렬이 되는 점을 해결할 수가 없었음
	-> 이를 해결하기 위해 큐와 우선순위 큐를 동시에 활용해서
	-> 큐는 {중요도,원래 index} 우선순위 큐는 {중요도}선언
	-> 그리고 queue.top.first 와 pq.top 이 같으면 출력 (count up)
	-> 아니라면 queue를 뒤로 보냄
	-> 즉 pq쪽에 index를 부여하지 않음!! (index로 인해 정렬이 안되게!!)
*/