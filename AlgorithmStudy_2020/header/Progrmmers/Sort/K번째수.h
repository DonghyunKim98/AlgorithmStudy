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
	알고리즘 포인트
	=> 우리가 sort해야하는 범위가 계속 변하므로 temp vector을 생성해줘야 함
*/
