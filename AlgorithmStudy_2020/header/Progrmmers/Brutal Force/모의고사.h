#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1,2,3,4,5 };
vector<int> two = { 2,1,2,3,2,4,2,5 };
vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % one.size()]) they[0]++;
        if (answers[i] == two[i % two.size()]) they[1]++;
        if (answers[i] == thr[i % thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(), they.end());
    for (int i = 0; i < 3; i++) {
        if (they[i] == they_max) answer.push_back(i + 1);
    }
    return answer;
}

/*
	1번 -> 12345
	2번 -> 21232425
	3번 -> 3311224455

	알고리즘 포인트
	=> 비교할 대상들을 미리 vector나 배열로 선언해서 비교하는 것. ->은근 자주 나옴.
    => max_element 라는 method : iterator 반환
*/