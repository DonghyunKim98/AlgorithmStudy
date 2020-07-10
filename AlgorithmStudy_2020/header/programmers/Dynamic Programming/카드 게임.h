#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 1;
//memoization
int dp[MAX][MAX];
vector <int> Left;
vector <int> Right;
int Size;
int DFS(int idxLeft, int idxRight) {
    //DFS Ż�� ����
    if (idxLeft == Size || idxRight == Size) return 0;
    //memoization �̿�
    if (dp[idxLeft][idxRight] != 0) return dp[idxLeft][idxRight];

    //case 3�� ������
    //1�� -> �� ������ ������ ���� ����
    int case1 = DFS(idxLeft + 1, idxRight + 1);
    //2�� -> ���ʸ� ������ ������ ���� ����
    int case2 = DFS(idxLeft + 1, idxRight);
    //3�� -> ������ Ŭ�� �������� ������ ������ ����
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
    �˰��� ����Ʈ
    => DP[a][b] : ���ʿ� a��° ī�尡 ���� ���� �ְ�, �����ʿ� b��° ī�尡 ���� ���� ������ ���� �� �ִ� �ִ� ������ DP[a][b] �̴�.
    
    ��ȭ��!:���������� ���������� ���ؼ� �� �����غ��� �Ѵ�.
            �� ���������� '����ī��' '������ī��' �׸��� "���� ���� �ִ� ī��" �� �����ϸ� �ƴ�.
            ��¥ ����ϴ�.

    STL : 2���� �迭�� �ʱ�ȭ �Ҷ����� memset �� �̿�����.
*/