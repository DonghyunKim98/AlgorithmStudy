/*#include <iostream>

using namespace std;

int main() {
	int number_in_decimal;
	cout << "2진법으로 나타내고 싶은 숫자를 하나 입력하세요: ";
	cin >> number_in_decimal;
	
	cout << "2진법으로 나타내면 ";
	for (int k = 31; k >= 0; k--) {
		if (number_in_decimal & (1 << k)) cout << "1";
		else cout << "0";
	}
	cout << " 입니다.";

}
*/
/*
	 Algorithm Point : Bitmask를 쓰는 정말 간단한 예제. Bit operation 별거 아니라고 생각했지만
					   사실 정말 많이 쓴다는 걸 알았다. 정리 잘해서 잘 써먹자. 계속 기억해두고.
					   실전 개발에서도 종종 써먹을 수 있을 것 같다.
*/