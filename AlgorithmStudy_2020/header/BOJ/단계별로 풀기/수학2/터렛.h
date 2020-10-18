#include <bits/stdc++.h>
//1002번 문제
using namespace std;

void Turret() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	//원과 원과의 관계
	while (T > 0) {
		int xpos1, xpos2, ypos1, ypos2;
		int root1, root2;
		cin >> xpos1 >> ypos1 >> root1 >> xpos2 >> ypos2 >> root2;
		double point_distance = sqrt(pow(xpos1 - xpos2, 2) + pow(ypos1 - ypos2, 2));

		//일치할때
		if (point_distance == 0 && root1 == root2) cout << -1 << "\n";
		//안에서 안 만날때 & 밖에서 안 만날떄
		else if (point_distance > root1 + root2 || point_distance < abs(root1 - root2))	 cout << 0 << "\n";
		//내접할때 & 외접할때
		else if (point_distance == root1 + root2 || point_distance == abs(root1 - root2)) cout << 1 << "\n";
		//두점에서 만날때
		else cout << 2 << "\n";
		T--;
	}
}