#include <bits/stdc++.h>
//https://mungto.tistory.com/22 참고
using namespace std;

//6+10 10+6 중 6+10으로 return 하게 함.
bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> vc;
    for (auto num : numbers)
        vc.push_back(to_string(num));
    //그냥 sort하면 30,3 이렇게 sort함
    //그래서 2개를 합쳤을때 더 큰값으로 sort하게 customizing
    sort(vc.begin(), vc.end(),comp);
    //처음 숫자가 0이라면 0을 반환
    if (vc.at(0) == "0") return "0";

    for (auto u : vc)
        answer += u;
    return answer;
}