#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 1;
//memoization
long long dp[101][MAX];

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    //i번째 도시까지
    for (int i = 0; i < travel.size(); i++) {
        int walkTime = travel[i][0], walkMoney = travel[i][1];
        int bikeTime = travel[i][2], bikeMoney = travel[i][3];
        //j의 시간제한까지 최대치 모금액 계산
        for (int j = 0; j <= K; j++) {
            //첫항 예외 처리
            if (i == 0) {
                //하나만 j까지 됨 (도보만 되는 경우)
                if (walkTime <= j && bikeTime > j) {
                    dp[i][j] = walkMoney;
                }
                //하나만 j까지 됨 (자전거만 되는 경우)
                else if (walkTime > j && bikeTime <= j) {
                    dp[i][j] = bikeMoney;
                }
                //둘다 j까지 됨
                else if (walkTime <= j && bikeTime <= j) {
                    dp[i][j] = max(walkMoney, bikeMoney);
                }
                continue;
            }
            //둘다 j까진 못함.(초과)
            if (walkTime > j && bikeTime > j){
                dp[i][j] = 0;
            }
            //하나만 j까지 됨. (도보만 되는 경우)
            else if (walkTime <= j && bikeTime > j) {
                if (dp[i - 1][j - walkTime] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j - walkTime] + walkMoney;
            }
            //하나만 j까지 됨 (자전거만 되는 경우)
            else if (walkTime > j && bikeTime <= j) {
                if (dp[i - 1][j - bikeTime] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j - bikeTime] + bikeMoney;
            }
            //둘다 j까지 됨.
            else if (walkTime <= j && bikeTime <= j) {
                long long  tempWalk = dp[i - 1][j - walkTime]==0 ? 0 : dp[i-1][j - walkTime] + walkMoney;
                long long  tempBike = dp[i - 1][j - bikeTime]==0 ? 0 : dp[i-1][j - bikeTime] + bikeMoney;
                dp[i][j] =  max(tempBike, tempWalk);
            }
        }
    }
    return dp[travel.size()-1][K];
}

/*
    K시간 -> 제약
    이 걸려있는 상태에서 모금액을 최대로 할 수 있는 방법.

    단순 무식하게 하면 O(2^n) Time complexity.
    BOJ 에서 포도주 시식과 같은 문제.
    수학이랑 정말 다른게 없다. 똑같은 문제임을 파악하는 것이 중요하다.

    D(i,k) => i번째 도시까지 이동하여 k 제한의 시간동안에 모금할 수 있는 최대치
    D(i,k) = - D(i-1,k) (W[i]>K) -> K보다 크면 아예 못 모금
             - max(D(i-1,K),D(i-1,K-W[i])+V[i]) (W[i]<=K)

    인데 조금 다른 부분은 무조건 가야 함. 즉 건너 뛸수는 없다는 말.
    따라서 max(D(i-1,K),D(i-1,K-W[i])+V[i] (W[i]<=K) 부분이
    그냥   D(i-1,K-W[i])+V[i] 가 됐다.
*/