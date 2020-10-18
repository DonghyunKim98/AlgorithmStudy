#include <bits/stdc++.h>
//15685�� ����
using namespace std;
int N;
bool MAP[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int check() {
	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <100; j++) {
			if (MAP[i][j] && MAP[i][j + 1] && MAP[i + 1][j] && MAP[i + 1][j + 1]) ret++;
		}
	}
	return ret;
}

int pow_2(int num) {
	int ret = 1;
	for (int i = 1; i <= num; i++) {
		ret *= 2;
	}
	return ret;
}
/*
	dir�� �ð�������� ȸ�� => (dir+1)%4
	��->��->��->��->��
	dir�� �ð�ݴ�������� ȸ�� =>(dir+3)%4
	��->��->��->��->��
	
	1����->�ð�
	2����->�ð�/�ݽð�
	3����->�ð�/�ð�/�ݽð�/�ݽð�
	4����->�ð�/�ð�/�ð�/�ݽð�/�ݽð�/�ð�/�ݽð�/�ݽð�
			   (�ݽð�/�ݽð�/�ð�/�ð�/�ݽð�/�ð�/�ð�)
	0����->��
	1����->��
	2����->��/��
	3����->��/��/��/��
	4����->��/��/��/��/��/��/��/��
	
	1. ������ ó���� �ð����
	2. �ι�°���� ����������� ������ �ݴ����

	0���� ->1��
	1���� ->1��
	2���� ->2��
	3���� ->4��
	4���� ->8��
	5���� ->16��
	n���� ->2^n��
*/
void process() {
	int ypos, xpos, dir, generation;
	cin >> xpos >> ypos >> dir >> generation;
	vector<bool> vc;
	for (int g = 0; g <= generation; g++) {
		bool is_over=false;
		//0���� ����ó��
		if (g == 0) {
			MAP[ypos][xpos] = true;
			ypos += dy[dir], xpos += dx[dir];
			MAP[ypos][xpos] = true;
			continue;
		}
		for (int i = 1; i <= pow_2(g-1); i++) {
			if (i == 1) {
				dir = (dir + 1) % 4;
				vc.push_back(true);
			}
			/*
				vc
				1���� -> [�ð�]
				2���� -> �ð� / [�ð�,�ݽð�]
				3���� -> �ð�, �ð�, �ݽð� / [�ð�,�ð�,�ݽð�,�ݽð�]
				4���� -> �ð�,�ð�,�ݽð�,�ð�,�ð�,�ݽð�,�ݽð�/[�ð�,
			*/
			else {
				bool is_clock_dir = !vc[vc.size() - 2 - (i - 2) * 2];
				is_clock_dir ? dir = (dir + 1) % 4 : dir = (dir + 3) % 4;
				vc.push_back(is_clock_dir);
			}
			ypos += dy[dir], xpos += dx[dir];
			//���� �ʰ��� �ϸ� break
			if (ypos < 0 && 100 < ypos && xpos < 0 && 100 < xpos) {
				is_over = true; break;
			}
			MAP[ypos][xpos] = true;
		}
		if (is_over) break;
	}
}

void solution() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		process();
	}
	cout << check();
}