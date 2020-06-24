#include <bits/stdc++.h>
//12865�� ����
//https://hibee.tistory.com/235 ����
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
            //�������� ������ ���԰� ������ ���Ժ��� �۰ų� ���ƾ� �ȴ�.
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
	�˰��� ��ȭ��
	D(i,k) => i��° ���Ǳ��� ����Ͽ� k �뷮�� ���濡 ������ ä�� ���� �ִ� ��ġ
	D(i,k) = - D(i-1,k) (W[i]>K) -> K���� ũ�� �ƿ� ������
			 - max(D(i-1,K),D(i-1,k-W[i]+V[i])) (W[i]<=K)

	�˰��� ����Ʈ!!!
	-> �ϴ� "An ���� n�� �־��� input�� ����..." ��� ���������� �������� ����!!
	-> ���⼭ An���� n�� "����"�� ���� ���� �ؾ���!!!! (���������� 2������ ����)
*/