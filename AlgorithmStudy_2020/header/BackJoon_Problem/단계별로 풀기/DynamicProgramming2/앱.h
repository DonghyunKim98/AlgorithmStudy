#include <bits/stdc++.h>
//7579번 문제
using namespace std;
const int MAX = 10000 + 1;
int N, M;
vector<int> app(100);
vector<int> cost(100);
int dp[101][MAX];
void solution() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> app[i];

	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		total += cost[i];
	}

	int answer = INT_MAX;
	//dp 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 10000; j++) {
			//base case 설정
			if (i == 0) {
				if (cost[0] <= j) dp[0][j] = app[0];
				continue;
			}
			//i번째 item 선택했을때의 최대값 
			//i번째 cost가 j보다 작아야 일단 선택할 수 있음.
			if (cost[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + app[i]);
			//i번째 item 선택X
			else
				dp[i][j] = dp[i - 1][j];

			//최소한 M을 확보했을때의 비용의 최솟값을 반환.
			//근데 dp[i][j] == M 을 하면 틀린다.
			//M을 확보했을때의 cost > M 초과했을때의 cost 일 수 있나??
			//=> 원래 dp[i][j]의 base case를 item들로 만들 수 있는 숫자들로만 했었기때문에 M을 초과할 수도 있었음.
			//즉 주어진 item들의 합으로 M을 못만들 수도 있기 때문!! 
			//ex) (10,20) 으론 15를 못만들잖아!
			if (dp[i][j] >= M) {
				answer = min(answer, j);
			}
		}
	}
	cout << answer;
}

/*
	알고리즘 해설
	=> 12865와 같은 문제
	=> DP[i][j] : i번째 item까지 사용할때 j비용으로 얻을 수 있는 최대의 byte
	=> DP[i][j] = DP[i-1][j] (i번째 item 선택 X => cost가 j보다 큼)
				= max(DP[i-1][j], DP[i-1][j-cost[i]] + app[i]) (i번째 item 선택 => cost가 j보다 작음)

	알고리즘 포인트
	-> 분명 처음볼때 12865랑 거의 비슷한 문제라고 생각했는데 산으로 간 이유는...
	-> i는 item까지 발상을 잘 했지만 j를 cost가 아닌 memory로 설정했기 때문.
	-> 이 문제에서 변수는 분명 3개다 (item,cost,memory)
	-> 어떤 것을 독립변수로, 어떤 것을 종속변수로 둘 것인지 충분한 경험을 통해 계속 쌓아가야한다.
	-> 그리고 1초라는 것도 분명 힌트였을텐데.. 1억번 연산이 1초니깐, 여기서 100*1000만 이면 10초가 걸림
	-> 분명 Time over 가 걸린 다는 것을 인지해야 했다.

	* Base case 설정에서도 간편하게 cost[0]일때만 했다. -> 근데 이래도 되는 이유가 뭐지?

*/