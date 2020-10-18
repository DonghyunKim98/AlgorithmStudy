#include<bits/stdc++.h>
//https://greenapple16.tistory.com/49 ����
using namespace std;
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long int begin = 0, end = (long long)times.back()*n;
    while (begin <= end) {
        long long sum = 0;
        long long int mid = (begin + end) / 2;
        //�־��� �ð����� �󸶳� �ɻ��� �� �ִ��� Ȯ��. ->���� ��
        for (int i = 0; i < times.size(); i++)
            sum += mid / times[i];
        if (sum < n)   begin = mid + 1;
        else end = mid - 1;
    }
    return begin;

}

/*
    �ּ� �ð� => 1
    �ִ� �ð� => ���� ���� �ɻ���� ��� ������� �Ѹ� �ɻ�

    �߿��� ���� �ɻ���� �ɻ��� �� �ִ� �ο��� �׳� ���� ���̶�� ��.
*/