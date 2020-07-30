#include <bits/stdc++.h>
//14499번 문제
using namespace std;
const int MAX = 20;
int N, M, K;
int arr[MAX][MAX];
int Dice[7];
typedef struct {
	int y, x;
}Diceidx;

typedef struct {
	int Up, Down, E , W , N, S;
}Position;


void solution() {
	ios::sync_with_stdio(0); cin.tie(0); 
	for (int i = 1; i <= 6; i++)
		Dice[i] = 0;

	int temp1, temp2;
	cin >> N >> M;
	cin >> temp1 >> temp2;
	cin >> K;
	Diceidx dice = { temp1,temp2 };
	//arr값 받기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int idx = 1;
	//Up Down E W N S
	Position DicePosition = {1,6,3,4,2,5};
	while (K > 0) {
		K--;
		int order;
		cin >> order;
		Position temp;
		//East -> North&SOuth 고정
		if (order == 1) {
			if (dice.x + 1 == M) continue;
			dice.x += 1;
			//Up Down E W N S
			temp = { DicePosition.W,DicePosition.E,DicePosition.Up,DicePosition.Down,DicePosition.N,DicePosition.S};
		}
		//West -> North&& South 고정
		else if (order == 2) {
			if (dice.x - 1 < 0) continue;
			dice.x -= 1;
			temp = { DicePosition.E,DicePosition.W,DicePosition.Down,DicePosition.Up,DicePosition.N,DicePosition.S};
		}
		//North ->East&West 고정
		else if (order == 3) {
			if (dice.y - 1 <0) continue;
			dice.y -= 1;
			temp = { DicePosition.S,DicePosition.N,DicePosition.E,DicePosition.W,DicePosition.Up,DicePosition.Down };
		}
		//South -> East&West 고정
		else {
			if (dice.y + 1 ==N)continue;
			dice.y += 1;
			temp = { DicePosition.N,DicePosition.S,DicePosition.E,DicePosition.W,DicePosition.Down,DicePosition.Up };
		}
		DicePosition = temp;
		//이동했을때 칸에 쓰여진 숫자가 0 -> 주사위의 바닥면을 칸에 복사
		if (!arr[dice.y][dice.x])
			arr[dice.y][dice.x] = Dice[DicePosition.Down];
		//이동했을때 칸에 쓰여진 숫자가 0이 아님 -> 주사위 바닥면에 해당 숫자가 복사
		else {
			Dice[DicePosition.Down] = arr[dice.y][dice.x];
			arr[dice.y][dice.x] = 0;
		}
		//주사위 윗면 출력
		std::cout << Dice[DicePosition.Up] << '\n';
	}
}

/*
	첫 생각 => 굴렸을때 각 장소마다 무조건 주사위의 idx가 고정된다고 생각 => X
	두번째 생각 => up의 idx만 정해지면 나머지 5개의 숫자 위치도 고정된다고 생각 => X
*/