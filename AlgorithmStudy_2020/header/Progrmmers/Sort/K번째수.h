#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> temp;
		for (int j = commands[i][0]; j <= commands[i][1]; j++) 
			temp.push_back(array[j-1]);
		sort(temp.begin(), temp.end());
		answer.push_back(temp.at(commands[i][2]-1));
	}
	return answer;
}

/*
	�˰��� ����Ʈ
	=> �츮�� sort�ؾ��ϴ� ������ ��� ���ϹǷ� temp vector�� ��������� ��
*/
