#include <bits/stdc++.h>
//12865번 문제
//https://hibee.tistory.com/235 참고
using namespace std;
int ans[100][100001];

int main()
{
    int n, m, a, b;
    vector<pair<int, int>> weight_profit;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        weight_profit.push_back({ a,b });
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0)
            {
                if (weight_profit[i].first <= j)
                    ans[i][j] = weight_profit[i].second;
                continue;
            }
            //넣으려는 물건의 무게가 가방의 무게보다 작거나 같아야 된다.
            if (weight_profit[i].first <= j)
                ans[i][j] = max(ans[i - 1][j], weight_profit[i].second + ans[i - 1][j - weight_profit[i].first]);
            else
                ans[i][j] = ans[i - 1][j];
        }
    }
    cout << ans[n - 1][m];
    return 0;
}


/*
	알고리즘 점화식
	D(i,k) => i번째 물건까지 사용하여 k 용량의 가방에 물건을 채울 때의 최대 가치
	D(i,k) = - D(i-1,k) (W[i]>K) -> K보다 크면 아예 못넣음
			 - max(D(i-1,K),D(i-1,k-W[i]+V[i])) (W[i]<=K)

	알고리즘 포인트!!!
	-> 일단 "An 에서 n을 주어진 input에 따라서..." 라고 고정관념을 가진것이 패착!!
	-> 여기서 An에서 n은 "무게"와 같이 생각 해야함!!!! (독립변수를 2가지로 생각)
*/