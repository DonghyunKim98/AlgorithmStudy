#include <bits/stdc++.h>
//10942번 문제
using namespace std;
const int MAX = 2000 + 1;
int arr[MAX];
bool dp[MAX][MAX];
void solution() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, false, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//base case 설정 -> gap이 0일때와 1일때.
	//why? 범위내의 원소의 개수가 홀수&짝수 구분해줘야 함.
	int gap = 0;
	for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
		dp[start_idx][start_idx + gap] = true;
	}
	gap = 1;
	for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
		if (arr[start_idx] == arr[start_idx + gap])
			dp[start_idx][start_idx + gap] = true;
	}

	//dp => 전처리.
	for (gap = 2; gap <= N; gap++) {
		for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
			if (arr[start_idx] == arr[start_idx + gap])
				if (dp[start_idx + 1][start_idx + gap - 1] == true)
					dp[start_idx][start_idx + gap] = true;
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		if (dp[start][end]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}

/*
	an이 중간인 펠린드롬의 개수는 셀 수 있음. 단 홀수개, 짝수개를 따로따로 세야함. 
	=> an-1의 정보를 이용할 수 없음. 다른 방법이 필요함.
	=> TLE 가 날것.

	an이 시작인 펠린드롬의 개수.
	an이 끝인 펠린드롬의 개수.
	
	알고리즘 포인트
	=> 왼쪽 끝과 오른쪽끝이 같은지를 계속 확인하면서 좁혀 나가면 된다.
	=> dp[start][end] = true (dp[start-1][end-1]==true && arr[start]=arr[end])
	
	* 결국 또 2차원 배열이고 매우 쉬운 아이디어 인데 떠올리지 못했다. 
	  LCS처럼 1차원적인 생각에서 머물렀기 때문.
	  한번 봤던 2차원 dp의 idea라면 쉽게 떠올리지만, 변형이 되면 아예 못한다는건 굉장히 나에게 아쉽다.
*/