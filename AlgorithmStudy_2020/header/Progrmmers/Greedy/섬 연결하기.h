#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 1;
int d[MAX];
int find(int node) {
    //�θ� �ڱ��ڽ��̸� ���� ��尡 �ֻ��� �θ�
    if (node == d[node]) return node;
    //�ƴ϶�� �ֻ��� �θ� ã��
    else return d[node] = find(d[node]);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //d[i]���� �θ� ����. �� ó���� ��� ��尡 �� �θ�(������Ʈ) ó��
    for (int i = 0; i < n; i++)
        d[i] = i;

    //������ ����ġ�� �������� �������� ���� => ũ�罺Į �˰���
    sort(costs.begin(), costs.end(),cmp);

    //��� ������ �˻�
    for (int i = 0; i < costs.size(); i++) {
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];

        //start�� end�� ������ ���� �ȵǾ� �ִٸ�
        if (start != end) {
            //start�� �θ� end�� ����
            d[start] = end;
            //������ ����ġ�� ����� ������
            answer += cost;
        }
        //����Ǿ� �ִٸ� �ƹ��� �ൿ�� ���� ����.
    }
    return answer;
}

/*
    ���� �ؼ� 
    =>�ּ� ��� , ��� �� ���� ����, �ٸ� ������ �ǳ� �� ����, ������ �ٲ� ���� ����(����� ����&����ġ ����)
    => �ּ� ���д� Ʈ��(Minimum Spanning Tree)�� Ǫ�� ����. 
    => ũ�罺Į �˰��� �̿�
    => å���� union-find ������ ������ ����.
    �˰��� ����Ʈ
    => ���⼱ ������ ������Ʈ�� Ʈ����°Ϳ� �԰��ؼ� '������ Ʈ���� �θ� �迭�� ��Ƶΰ�'
    => �θ� ���� == ���� / �θ� ���� �ʴ� ==���� ���� �ȵ� ���� ó��
    (å����  if(!same(a,b)) unite(a,b); �� ó�� ����)
*/
