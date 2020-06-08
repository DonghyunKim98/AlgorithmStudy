#include <bits/stdc++.h>
#include <intrin.h>
using namespace std;
//비트 병렬 알고리즘 예시
string a, b;
int A, B;
void HammingDistance() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	cout << "0과 1로 이루어진 문자열 2개를 입력하세요.\n";
	cin >> a >> b;
	A = stoi(a);
	B = stoi(b);

	//process
	int result = __popcnt(A^B);

	//output
	cout << "주어진 문자열의 해밍 거리는 " << result << "입니다";
}

/*
	문제점) stoi를 하면 10진법으로 바꾼다.
			2진법으로 바꿔야하는데 흠..
*/