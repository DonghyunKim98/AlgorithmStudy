#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
bool arr[MAX];

int solution(vector<int> a) {
    int answer;
    //맨 왼쪽과 오른쪽은 무조건 되므로
    a.size() == 1 ? answer = 1 : answer = 2;
   
    //왼쪽 진행
    int left_min_num = a[0];
    for (int i = 1; i < a.size()-1; i++) {
        //이번 숫자가 왼쪽에서 가장 작은 숫자다.
        if (a[i] < left_min_num) {
            left_min_num = a[i];
            answer++;
            arr[i] = true;
        }
    }
    //오른쪽 진행
    int right_min_num=a[a.size()-1];
    for (int i = a.size() - 2; i >= 1; i--) {
        if (a[i] < right_min_num) {
            right_min_num = a[i];
            if (arr[i]) continue;
            answer++;
            arr[i] = true;
        }
    }
    return answer;
}

/*
        번호가 큰게 터지는게 규칙
        -----<왼쪽>a<오른쪽>------
        [0,a의 idx]까지 a가 가장 작으면    -> 문제가 없어
        [0,a의 idx]까지 a가 가장 작지 않음
        -> 문제가 있다. => 왼쪽에서 제일 큰게 남음
                       => 요거는 제거할 수 있음
                       => 근데 오른쪽에서도

        [왼쪽에서 제일큰값]a[오른쪽에서 제일 큰값]
        =>못한다!
        a->k번째로 큰값&p
        오케이!

*/