#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 1;
//memoization
int dp[MAX][MAX];
vector <int> Left;
vector <int> Right;
int Size;
int DFS(int idxLeft, int idxRight) {
    //DFS 탈출 조건
    if (idxLeft == Size || idxRight == Size) return 0;
    //memoization 이용
    if (dp[idxLeft][idxRight] != 0) return dp[idxLeft][idxRight];

    //case 3개 따지기
    //1번 -> 다 버리고 점수를 얻지 못함
    int case1 = DFS(idxLeft + 1, idxRight + 1);
    //2번 -> 왼쪽만 버리고 점수를 얻지 못함
    int case2 = DFS(idxLeft + 1, idxRight);
    //3번 -> 왼쪽이 클때 오른쪽을 버리고 점수를 얻음
    int case3 = -1;
    if (Left[idxLeft] > Right[idxRight]) case3 = DFS(idxLeft, idxRight + 1) + Right[idxRight];

    dp[idxLeft][idxRight] = max(max(case1, case2), case3);
    return dp[idxLeft][idxRight];
}

int solution(vector<int> left, vector<int> right) {
    Left = left;
    Right = right;
    Size = left.size();
    int answer = DFS(0, 0);
    return answer;
}

/*
    알고리즘 포인트
    => DP[a][b] : 왼쪽에 a번째 카드가 가장 위에 있고, 오른쪽에 b번째 카드가 가장 위에 있을때 얻을 수 있는 최대 점수는 DP[a][b] 이다.
    
    점화식!:독립변수가 무엇인지에 대해서 잘 생각해봐야 한다.
            이 문제에서는 '왼쪽카드' '오른쪽카드' 그리고 "제일 위에 있는 카드" 로 생각하면 됐다.
            진짜 대단하다.

    STL : 2차원 배열을 초기화 할때에는 memset 을 이용하자.
*/