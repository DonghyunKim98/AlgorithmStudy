#include <bits/stdc++.h>
//5373번 문제
/*            U
		  0  1  2
		  3  4  5
		  6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
		-----------
		  9  10 11
		  12 13 14
		  15 16 17
		  D
*/
//0번면 -> U(윗면) , 1번면 -> D(아랫면), 2번면 -> F(앞면), 3번면 -> B(뒷면), 4번면 -> L(왼쪽면), 5번면 -> R(오른쪽면)
//1번->w, 2번-> y, 3번->r, 4번-> o, 5번-> g, 6번 b.
enum FACE{U,D,F,B,L,R,SIZE};
int cube[SIZE][3][3];
char init[7] = "wyrogb";
char arr[55];
char temp[3][3];
int conv[256];
using namespace std;
//맞다아져 있는 면들의 idx 기입
//코드와 데이터는 분리!!
int rot[6][12] = {
	{36,37,38,18,19,20,45,46,47,27,28,29},        //U
	{33,34,35,51,52,53,24,25,26,42,43,44},        //D
	{6,7,8,44,41,38,11,10,9,45,48,51},            //F
	{2,1,0,53,50,47,15,16,17,36,39,42},            //B
	{0,3,6,35,32,29,9,12,15,18,21,24},            //L
	{8,5,2,26,23,20,17,14,11,27,30,33}            //R
};

/*
	시계 방향만 생각해도 됨
	why?) 반시계 방향 1번 == 시계 방향 3번
		  어차피 시물레이션 문제라서 Time Complexity에 대한 걱정은 안 해도 됨.
*/
void rotate(FACE f, int cnt) {
	char que[12];

	while (cnt--) {
		//큐에 데이터 넣기
		for (int i = 0; i < 12; i++) que[i] = arr[rot[f][i]];
		//큐를 3칸 밀어서 다시 넣기
		for (int i = 0; i < 12; i++) arr[rot[f][i]] = que[(i + 3) % 12];
		//면 돌리기
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[j][2 - i] = arr[cube[f][i][j]];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[cube[f][i][j]] = temp[i][j];
	}
}
void initialization() {
	conv['-'] = 3;
	conv['+'] = 1;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;
	//큐브 인덱스 부여하기
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < 3; j++) 
			for (int k = 0; k < 3; k++) cube[i][j][k] = i * 9 + j * 3 + k;
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	initialization();
	
	int N; string conm;
	cin >> N;
	while (N--) {
		//큐브 초기화
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 9; j++) {
				arr[i * 9 + j] = init[i];
			}
		int cnt;
		cin >> cnt;
		while (cnt--) {
			cin >> conm;
			int f = conv[conm[0]], cnt2 = conv[conm[1]];
			rotate((FACE)f, cnt2);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << arr[cube[U][i][j]];
			cout << '\n';
		}
	}

}