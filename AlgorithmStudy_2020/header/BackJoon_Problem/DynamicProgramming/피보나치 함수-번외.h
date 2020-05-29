#include <bits/stdc++.h>

using namespace std;

//1003�� ����
/*
    �̰� Ʋ�� ������ �������� 0�� 1�� �ᱹ ������ �ؾ��ϴµ�, ���ٵ� ���ϰ� Memoization�� ���Ƴ��� ����.
*/
//���� ����� ���� �迭 (0�� 1)
vector<bool> result0;
vector<bool> result1;

//�ٽ�! Memoization�� ���� �迭
bool ready[1000000] = { false, };
int value[1000000];


int fibonacci(int n) {
    if (n == 0) {
        result0.push_back(true);
    }
    else if (n == 1) {
        result1.push_back(true);
    }
    //n-1 ���� �ƴ°��� �ݵ�� �� �������� �� ���ۿ� ����
    if (ready[n - 1]) {
        value[n] = value[n - 1] + value[n - 2], ready[n] = true;
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
    //�ܼ��� �־��� �Ǻ���ġ �Լ��� �״�� ���� �翬�� �ð�����
    //base case ����
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
