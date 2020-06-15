#include <bits/stdc++.h>
//10872¹ø ¹®Á¦
using namespace std;

int Recurrsion(int _input) {
	if (_input == 1) return 1;
	else if (_input == 0) return 1;
	else return _input * Recurrsion(_input-1);
}

void Factorial() {
	int N;
	cin >> N;
	cout << Recurrsion(N)<<"\n";

}