#include <bits/stdc++.h>
//2588�� ����
using namespace std;

void Multiply() {
	int A, B;
	cin >> A >> B;
	cout << A * (B % 10) << endl;
	cout << A * ((B / 10) % 10) << endl;
	cout << A * (B / 100) <<endl;
	cout << A * B;
}