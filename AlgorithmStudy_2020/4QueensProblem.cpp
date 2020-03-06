/*#include <iostream>

using namespace std;
//해의 개수를 새는 value
int Count;
int n;
//체스판 칸을 indexing 하기위한 배열 3가지
//	1) col -> 열
//	2) diag1 -> 우상향 대각선
//	3) diag2 -> 우하향 대각선
//	그리고 초기화 안하면 동적할당해서 주소값 튀어나옴 무조건 전체 0으로 초기화!!
//	diag1과 diag2의 경우에는 index가 4까지만 있는게 아니라 6까지있다!!!


int* col = new int[4]{ 0, };
int* diag1 = new int[6]{ 0, };
int* diag2 = new int[6]{ 0, };
//Problem을 푸는 함수
void search(int);
int main() {
	//기본 초기화
	n = 4;
	Count = 0;
	//function call
	search(0);
	cout << "4*4의 체스판에서 서로 공격하지 않는 퀸이 놓일 수 있는 방법은 " << Count << "개 입니다.";
}
//x는 열의 index, y는 행의 index , n은 체스판의 크기
void search(int y) {
	if (y == n) {
		Count++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x + n - 1 - y]) continue; //하나라도 1이면 퀸이 올수 없음! (유망하지않으니 부모로 돌아감)
		col[x] = diag1[x + y] = diag2[x + n - 1 - y] = 1; //퀸이 갈수있다! (유망)
		search(y + 1); // 유망하니 탐색
		col[x] = diag1[x + y] = diag2[x + n - 1 - y] = 0; //원상복귀 (모든곳이 일단 못갈수 있다고 생각)
	}

}
*/
/*
	해맸던 이유: 1) or 연산자를 까먹음... 하나라도 false면 false인줄 알았는데 하나라도 true면 true 였다.
				 2) 0이면 갈수 없고 (queen이 공격할수있는 곳) 1이면 갈 수 있다는 것도 정확히 이해 X
				 3) 배열을 동적으로 할당했을때 아무것도 초기화하지 않으면 모든 element에 주소값이 할당됨
				   -> 그래서 전체 배열을 0으로 할당을 해야했음.
			     4)  diag1 과 diag2의 경우 index가 n만큼이 아님.... index가 항상 n까지만 있다고 생각 X!
	Algorithm Point : Backtracking의 기본!! 유망하다면 가고 (기존 퀸들이 공격 X) 유망하지 않다면 안가고(기존 퀸들이 공격)
*/