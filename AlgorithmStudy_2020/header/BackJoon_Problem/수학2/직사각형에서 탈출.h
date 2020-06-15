#include <iostream>
#include <algorithm>
//1085¹ø ³ë·¡
using namespace std;

void Rectangular() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	cout << min(min(w-x,x),min(h-y,y));
}