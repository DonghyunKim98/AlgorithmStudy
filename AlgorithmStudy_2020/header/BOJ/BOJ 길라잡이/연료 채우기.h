#include <bits/stdc++.h>
//1826번 문제
using namespace std;
const int MAX = 10000000 + 1;
typedef pair<int, int> pii;
int N,destination,fuel;
//오름차순
struct cmp {
	bool operator()(pii& a, pii& b) {
		return a.first > b.first;
	}
};
//내림차순
struct cmp2 {
	bool operator()(pii& a, pii& b) {
		return a.second < b.second;
	}
};
//첫번째 pq -> 주유소를 거리순으로 오름차순으로 배치(min heap)
priority_queue<pii,vector<pii>,cmp> pq;
//두번쨰 pq -> 갈 수 있는 주유소를 기름을 넣을 수 있는 양으로 내림차순 배치(max heap)
priority_queue<pii,vector<pii>,cmp2> pq2;


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
	cin >> destination >> fuel;
	int ans = 0;
	//기름이 목적지까지 갈 수 있을 정도가 되면 stop 
	//목적지까지의 거리가 destination인데 현재 기름양인 fuel가 destionation보다 많으면 갈 수 있으므로 더 주유소를 안 들려도 됨
	while (fuel < destination) {
		//가지고 있는 기름으로 갈 수 있는 주유소는 다 넣는다
		while (!pq.empty() && fuel >= pq.top().first) {
			pq2.push(pq.top());
			pq.pop();
		}
		//갈 수 있는 주유소가 없다! -> -1출력
		if (pq2.empty()) {
			ans = -1;
			break;
		}
		//갈 수 있는 주유소중 가장 기름을 많이 먹을 수 있는 곳으로 간다
		fuel += pq2.top().second;
		pq2.pop();
		ans++;
	}
	cout << ans;
}

/*
	1. k번째 주유소를 들리는경우 -> 지금 현재 있는 양으로 k+1번째까지 못 가는 경우
	=> 그렇지만, k+1번째 까지 충분히 가지만, k번째 주유소에서 매우 많은 양으로 충전할 수 있다면
				들려야함
	
	그렇다면 우선순위가
	1) 당장 다음 주유소까지 갈 기름이 없다 -> 들림
	2) 당장 다음 주유소까지 갈 수 있지만 이곳에서 기름을 많이 충전할 수 있다 -> 들림..?
	  -> 단순히 sort를 이용해서 들리면 되는것인가?
*/

/*
	<정답 생각>
	1) 현재 있는 연료로 갈 수 있는 주유소를 찾는다. 
		-> 이때 갈 수 있는 주유소가 없다면 -1을 출력
	2) 갈 수 있는 주유소중에, 제일 기름을 많이 넣을 수 있는 곳에서 기름을 넣는다.

	3) 1)->2) 를 반복할때 이전 단계에 있는 주유소에서 더 많이 충전할 수도 있으므로 우선순위 큐를 이용해서 관리한다.

	* 기름만으로도 거리를 관리할 수 있다. 이 부분을 생각하지 못한게 어려운듯.
*/