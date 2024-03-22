#include <bits/stdc++.h>
// 9663???? ??????
using namespace std;
int n;
int cnt = 0;
int col[15];
int diag1[28];
int diag2[28];

void DFS(int y)
{
	if (y == n)
	{
		cnt++;
		return;
	}
	else
	{
		for (int x = 0; x < n; x++)
		{
			if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
				continue;
			col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
			DFS(y + 1);
			col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
		}
	}
}

void NQueen()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill_n(col, 15, 0);
	fill_n(diag1, 28, 0);
	fill_n(diag2, 28, 0);
	cin >> n;
	DFS(0);
	cout << cnt;
}