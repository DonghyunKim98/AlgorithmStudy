#include <bits/stdc++.h>
//https://mungto.tistory.com/22 ����
using namespace std;

//6+10 10+6 �� 6+10���� return �ϰ� ��.
bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> vc;
    for (auto num : numbers)
        vc.push_back(to_string(num));
    //�׳� sort�ϸ� 30,3 �̷��� sort��
    //�׷��� 2���� �������� �� ū������ sort�ϰ� customizing
    sort(vc.begin(), vc.end(),comp);
    //ó�� ���ڰ� 0�̶�� 0�� ��ȯ
    if (vc.at(0) == "0") return "0";

    for (auto u : vc)
        answer += u;
    return answer;
}