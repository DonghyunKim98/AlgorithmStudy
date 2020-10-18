#include <bits/stdc++.h>
using namespace std;
//https://greenapple16.tistory.com/86 ����
bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> mp_count;
	vector<pair<string, int>> vc;

	//�帣 �� ���Ƚ�� ī��Ʈ
	//mp_count�� key ���� �������� �ʾƵ� �ٷ� ��
	for (int i = 0; i < genres.size(); i++)
		mp_count[genres[i]] += plays[i];
	map<string, int>::iterator it = mp_count.begin();
	//sort�� ���� ���� ���Ϳ� ����
	for (it = mp_count.begin(); it != mp_count.end(); it++)
		vc.push_back(make_pair(it->first, it->second));

	//��� Ƚ���� �������� sort
	sort(vc.begin(), vc.end(),cmp);
	//�帣�� ���� ����� �� �� ã��
	for (int i = 0; i < vc.size(); i++) {
		int first = 0, second = 0, first_index = 0, second_index = 0;
		for (int j = 0; j < genres.size(); j++) {
			//�帣�� �� ���鼭 (map�� key���� �帣�ϱ�) ��ġ�ϸ� -> ���� ���� ����� Ƚ��
			if (genres[j] == vc[i].first) {
				if (plays[j] > first) {
					second = first;
					second_index = first_index;
					first = plays[j];
					first_index = j;
				}
				else if(plays[j]>second) {
					second = plays[j];
					second_index = j;
				}
			}
		}
		answer.push_back(first_index);
		//�帣�� 2�� �̻��� ���� ���� ��쿡�� �ٹ��� �ֱ�.
		if (second > 0)
			answer.push_back(second_index);
	}
	return answer;
}

/*
	�˰��� ����Ʈ -> �ѹ��� �� ó���������� �ϳ��ϳ� ó������

	���� ������ '�����' ����
	���� "���� ���� ����� �帣�� top2������ 2����" �̶�� �߸� �о���.
*/