#include <iostream>
#include <algorithm>
//1085�� �뷡
using namespace std;

void Rectangular() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	cout << min(min(w-x,x),min(h-y,y));
}