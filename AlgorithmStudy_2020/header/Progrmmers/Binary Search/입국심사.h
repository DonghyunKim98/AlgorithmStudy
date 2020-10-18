#include<bits/stdc++.h>
//https://greenapple16.tistory.com/49 참고
using namespace std;
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long int begin = 0, end = (long long)times.back()*n;
    while (begin <= end) {
        long long sum = 0;
        long long int mid = (begin + end) / 2;
        //주어진 시간에선 얼마나 심사할 수 있는지 확인. ->나눈 몫
        for (int i = 0; i < times.size(); i++)
            sum += mid / times[i];
        if (sum < n)   begin = mid + 1;
        else end = mid - 1;
    }
    return begin;

}

/*
    최소 시간 => 1
    최대 시간 => 가장 느린 심사관이 모든 사람들을 한명씩 심사

    중요한 것은 심사관이 심사할 수 있는 인원은 그냥 나눈 몫이라는 것.
*/