#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 1;
//memoization
long long dp[101][MAX];

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    //i��° ���ñ���
    for (int i = 0; i < travel.size(); i++) {
        int walkTime = travel[i][0], walkMoney = travel[i][1];
        int bikeTime = travel[i][2], bikeMoney = travel[i][3];
        //j�� �ð����ѱ��� �ִ�ġ ��ݾ� ���
        for (int j = 0; j <= K; j++) {
            //ù�� ���� ó��
            if (i == 0) {
                //�ϳ��� j���� �� (������ �Ǵ� ���)
                if (walkTime <= j && bikeTime > j) {
                    dp[i][j] = walkMoney;
                }
                //�ϳ��� j���� �� (�����Ÿ� �Ǵ� ���)
                else if (walkTime > j && bikeTime <= j) {
                    dp[i][j] = bikeMoney;
                }
                //�Ѵ� j���� ��
                else if (walkTime <= j && bikeTime <= j) {
                    dp[i][j] = max(walkMoney, bikeMoney);
                }
                continue;
            }
            //�Ѵ� j���� ����.(�ʰ�)
            if (walkTime > j && bikeTime > j){
                dp[i][j] = 0;
            }
            //�ϳ��� j���� ��. (������ �Ǵ� ���)
            else if (walkTime <= j && bikeTime > j) {
                if (dp[i - 1][j - walkTime] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j - walkTime] + walkMoney;
            }
            //�ϳ��� j���� �� (�����Ÿ� �Ǵ� ���)
            else if (walkTime > j && bikeTime <= j) {
                if (dp[i - 1][j - bikeTime] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j - bikeTime] + bikeMoney;
            }
            //�Ѵ� j���� ��.
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
    K�ð� -> ����
    �� �ɷ��ִ� ���¿��� ��ݾ��� �ִ�� �� �� �ִ� ���.

    �ܼ� �����ϰ� �ϸ� O(2^n) Time complexity.
    BOJ ���� ������ �ýİ� ���� ����.
    �����̶� ���� �ٸ��� ����. �Ȱ��� �������� �ľ��ϴ� ���� �߿��ϴ�.

    D(i,k) => i��° ���ñ��� �̵��Ͽ� k ������ �ð����ȿ� ����� �� �ִ� �ִ�ġ
    D(i,k) = - D(i-1,k) (W[i]>K) -> K���� ũ�� �ƿ� �� ���
             - max(D(i-1,K),D(i-1,K-W[i])+V[i]) (W[i]<=K)

    �ε� ���� �ٸ� �κ��� ������ ���� ��. �� �ǳ� �ۼ��� ���ٴ� ��.
    ���� max(D(i-1,K),D(i-1,K-W[i])+V[i] (W[i]<=K) �κ���
    �׳�   D(i-1,K-W[i])+V[i] �� �ƴ�.
*/