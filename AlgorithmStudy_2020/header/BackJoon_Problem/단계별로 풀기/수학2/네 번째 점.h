#include <iostream>
//3009¹ø ¹®Á¦
using namespace std;

void FourthPoint() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int xpos[4], ypos[4];

	for (int i = 0; i < 3; i++) {
		cin >> xpos[i] >> ypos[i];
	}

	if (xpos[0] == xpos[1]) xpos[3] = xpos[2];
	else if (xpos[0] == xpos[2]) xpos[3] = xpos[1];
	else xpos[3] = xpos[0];

	if (ypos[0] == ypos[1]) ypos[3] = ypos[2];
	else if (ypos[0] == ypos[2]) ypos[3] = ypos[1];
	else ypos[3] = ypos[0];

	cout << xpos[3] << " " << ypos[3];
}
