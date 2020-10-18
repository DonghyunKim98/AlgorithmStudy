#include<bits/stdc++.h>
using namespace std;
//17947번 문제
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second
#define all(v) (v).begin(), (v).end()

ll n, pos[5010], C, M, psum[5010];
pll dp[5010];

inline int cal(int S, int E) {
    ll ret = 0;
    int mid = (S + E) / 2;
    ret += psum[E] - psum[mid];
    ret -= psum[mid - 1] - psum[S - 1];
    if ((E - S + 1) % 2 == 0) ret -= pos[mid];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pos[i];
    sort(pos + 1, pos + 1 + n);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + pos[i];
    cin >> C >> M;

    dp[0] = { 0,0 };
    for (int i = 1; i <= n; ++i) {
        dp[i] = { LLONG_MAX, LLONG_MAX };
        for (int j = 1; j <= i; ++j)
            dp[i] = min(dp[i], { dp[j - 1].xx + cal(j,i) * C + M, dp[j - 1].yy + 1 });
    }
    cout << dp[n].xx << ' ' << dp[n].yy;
}


/*
    Green님의 코드
    1. dp자체는 어렵지 않다 많이 보았던 모양
        dp[i] => {i번째 손님까지의 최소 비용, 최소 가게}
        dp[i] = min(dp[i],{dp[j-1]+[j,i]까지 가게를 한개 더 세웠을때의 최소비용,dp[j-1]+1}) 
            * 즉 [1,j-1]까진 거기에 있는 가게들로 퉁치고, [j,i] 구간에서만 최솟값을 구하는 것
    2. 중요한 건 최솟값을 어떻게 구하냐는 건데, 주어진 손님들 위치 사이 어딘가에 존재해서
       |a1-X| + |a2-X| + ... + |ak - X| 가 최솟값이 되는 곳을 구하는 것.
       => 이는 중앙값이 무조건 최솟값이 됨이 알려져 있음 (1차방정식의 절대값 그래프)
       => 그래서 정렬한 배열에서 주어진 start와 end의 index의 절반에 위치한 것이 중앙값   
    
    3. 이때 중앙값을 구할때, 누적합을 이용하면 편리하게 구할 수 있음
        => 그래서 누적합을 전처리를 미리 함
        => 그리고 간격이 홀수인가 짝수에 대한 예외 처리만 하면 된다.

    배워야 할 점
    1. cal은 계속 호출당함 inline으로 작성할 것
    2. mid를 계산할때 bitshift를 이용해볼것. (오른쪽 bitshift를 1칸주면 1/2배가 됨)
    3. 홀수 짝수 여부를 계산할때도 bitshift를 이용하면 편리 (&1 을 해서 1이 나오면 홀수 0이나오면 짝수)

*/