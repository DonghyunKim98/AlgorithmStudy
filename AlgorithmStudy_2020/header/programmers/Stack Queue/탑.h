#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    //{height,index}
    stack <pair<int,int>> s;
    for (int i = 0; i < heights.size();i++)
        s.push(make_pair(heights[i],i+1));

    for (int i = heights.size() - 1; i >= 0; i--) {
        //���� �ִ� ��ġ�� ���� ���� 
        int current_top = s.top().first;
        s.pop();
        stack<pair<int,int>> temp;
        //���� ã�Ҵٸ� ����������! -> for���� ó�� ���ö� ���� ��.
        while (!s.empty()) {
            if (s.top().first > current_top) {
                answer[i] = s.top().second;
                break;
            }
            else {
                temp.push(s.top());
                s.pop();
            }
        }
        if (s.empty()) answer[i] = 0;

        //temp�� �ִ� ģ���� �ٽ� ����
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    return answer;
}

/*
    1. �߻��� ��ȣ�� ���� ž���� ���� ž������ ����
    2. �� �� ���ŵ� ��ȣ�� �ٸ� ž���� �۽����� ����
    3. ��ȣ �߻�� �������� �۽� (���� ���� ���ʿ� �ְ�  ž�� �۽��� ����-> �ε����� ū ���� )
    4. index�� 1���� ����.

    [6,9,5,7,4]
*/