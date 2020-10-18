#include <bits/stdc++.h>
//14499�� ����
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
	//arr�� �ޱ�
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
		//East -> North&SOuth ����
		if (order == 1) {
			if (dice.x + 1 == M) continue;
			dice.x += 1;
			//Up Down E W N S
			temp = { DicePosition.W,DicePosition.E,DicePosition.Up,DicePosition.Down,DicePosition.N,DicePosition.S};
		}
		//West -> North&& South ����
		else if (order == 2) {
			if (dice.x - 1 < 0) continue;
			dice.x -= 1;
			temp = { DicePosition.E,DicePosition.W,DicePosition.Down,DicePosition.Up,DicePosition.N,DicePosition.S};
		}
		//North ->East&West ����
		else if (order == 3) {
			if (dice.y - 1 <0) continue;
			dice.y -= 1;
			temp = { DicePosition.S,DicePosition.N,DicePosition.E,DicePosition.W,DicePosition.Up,DicePosition.Down };
		}
		//South -> East&West ����
		else {
			if (dice.y + 1 ==N)continue;
			dice.y += 1;
			temp = { DicePosition.N,DicePosition.S,DicePosition.E,DicePosition.W,DicePosition.Down,DicePosition.Up };
		}
		DicePosition = temp;
		//�̵������� ĭ�� ������ ���ڰ� 0 -> �ֻ����� �ٴڸ��� ĭ�� ����
		if (!arr[dice.y][dice.x])
			arr[dice.y][dice.x] = Dice[DicePosition.Down];
		//�̵������� ĭ�� ������ ���ڰ� 0�� �ƴ� -> �ֻ��� �ٴڸ鿡 �ش� ���ڰ� ����
		else {
			Dice[DicePosition.Down] = arr[dice.y][dice.x];
			arr[dice.y][dice.x] = 0;
		}
		//�ֻ��� ���� ���
		std::cout << Dice[DicePosition.Up] << '\n';
	}
}

/*
	ù ���� => �������� �� ��Ҹ��� ������ �ֻ����� idx�� �����ȴٰ� ���� => X
	�ι�° ���� => up�� idx�� �������� ������ 5���� ���� ��ġ�� �����ȴٰ� ���� => X
*/