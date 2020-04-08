#include <bits/stdc++.h>

using namespace std;

//1003번 문제

//정답 출력을 위한 배열 (0과 1)
vector<bool> result0;
vector<bool> result1;

//핵심! Memoization을 위한 배열
bool ready[1000000] = { false, };
//이 value가 (0이 몇번쓰이는지, 1이 몇번쓰이는지, 그리고 그 값은 몇인지
tuple<int,int,int> value[1000000];



tuple<int,int,int> fibonacci(int n) {
    if (n == 0) {
        result0.push_back(true);
    }
    else if (n == 1) {
        result1.push_back(true);
    }
    //n-1 항을 아는것은 반드시 그 이전항을 알 수밖에 없음
    if (ready[n - 1]) {
        value[n] = value[n - 1] + value[n - 2], ready[n] = true;
        /*
        get<0>(value[n]) = get<0>(value[n - 1]) + get<0>(value[n - 2]);
        get<1>(value[n]) = get<1>(value[n - 1]) + get<1>(value[n - 2]);
        get<2>(value[n]) = get<2>(value[n - 1]) + get<2>(value[n - 2]);
        */
        ready[n] = true;
    }
    else if (ready[n - 2]) {
        value[n - 1] = fibonacci(n - 1), ready[n - 1] = true;
        value[n] = value[n - 1] + value[n - 2], ready[n] = true;
    }
    else {
        value[n - 1] = fibonacci(n - 1), ready[n - 1] = true;
        value[n - 2] = fibonacci(n - 2), ready[n - 2] = true;
        value[n] = value[n - 1] + value[n - 2];
    }
    return value[n];
}

void FibonacciFunction() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    //단순히 주어진 피보나치 함수를 그대로 쓰면 당연히 시간오바
    //base case 설정
    value[0] = 0, value[1] = 1;
    ready[0] = 0, ready[1] = 1;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        fibonacci(temp);
        cout << result0.size() << ' ' << result1.size();
        result0.clear();
        result1.clear();
    }
    return;
}