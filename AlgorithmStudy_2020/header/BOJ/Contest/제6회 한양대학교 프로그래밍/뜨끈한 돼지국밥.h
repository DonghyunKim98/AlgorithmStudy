#include<bits/stdc++.h>
using namespace std;
//17947�� ����
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
    Green���� �ڵ�
    1. dp��ü�� ����� �ʴ� ���� ���Ҵ� ���
        dp[i] => {i��° �մԱ����� �ּ� ���, �ּ� ����}
        dp[i] = min(dp[i],{dp[j-1]+[j,i]���� ���Ը� �Ѱ� �� ���������� �ּҺ��,dp[j-1]+1}) 
            * �� [1,j-1]���� �ű⿡ �ִ� ���Ե�� ��ġ��, [j,i] ���������� �ּڰ��� ���ϴ� ��
    2. �߿��� �� �ּڰ��� ��� ���ϳĴ� �ǵ�, �־��� �մԵ� ��ġ ���� ��򰡿� �����ؼ�
       |a1-X| + |a2-X| + ... + |ak - X| �� �ּڰ��� �Ǵ� ���� ���ϴ� ��.
       => �̴� �߾Ӱ��� ������ �ּڰ��� ���� �˷��� ���� (1���������� ���밪 �׷���)
       => �׷��� ������ �迭���� �־��� start�� end�� index�� ���ݿ� ��ġ�� ���� �߾Ӱ�   
    
    3. �̶� �߾Ӱ��� ���Ҷ�, �������� �̿��ϸ� ���ϰ� ���� �� ����
        => �׷��� �������� ��ó���� �̸� ��
        => �׸��� ������ Ȧ���ΰ� ¦���� ���� ���� ó���� �ϸ� �ȴ�.

    ����� �� ��
    1. cal�� ��� ȣ����� inline���� �ۼ��� ��
    2. mid�� ����Ҷ� bitshift�� �̿��غ���. (������ bitshift�� 1ĭ�ָ� 1/2�谡 ��)
    3. Ȧ�� ¦�� ���θ� ����Ҷ��� bitshift�� �̿��ϸ� �� (&1 �� �ؼ� 1�� ������ Ȧ�� 0�̳����� ¦��)

*/