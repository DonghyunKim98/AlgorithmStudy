#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int current_price = prices.at(i);
		int cnt = 0;
		//자기 자신부터 비교함으로서 바로 자기자신때의 1초를 구현
		for (int j = i; j <= prices.size(); j++) {
			//마지막(j=prices.size())까지 왔다면 안 떨어진걸로 간주.
			//이때는 시간이 흐른게 아니므로 cnt-1을 해준다.
			if (j == prices.size()) {
				answer.push_back(cnt-1);
				break;
			}
			int comp_price = prices.at(j);
			//주식 가격이 떨어졌다면 answer vector에 cnt 값을 push
			if (comp_price < current_price) {
				answer.push_back(cnt);
				break;
			}
			//떨어지지 않았다면 cnt값 증가
			else cnt++;
		}
	}
	return answer;
} 

//https://mungto.tistory.com/6 참고 ->stack이용
vector<int> solution2(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;
    for (int i = 0; i < size; i++) {
        //스택이 비어있지않고 스택마지막 값이 현재값보다 크다면
        //-> 가격이 떨어졌다면
        while (!st.empty() && prices[st.top()] > prices[i]) {
            //가격이 떨어졌으므로 i - 스택 마지막값 대입
            answer[st.top()] = i - st.top();
            //값제거
            st.pop();
            //반복문인 이유: 가격이 같은값이 유지되었을경우
            //현재값보다 계속작으므로 1개차이씩 넣어주기 위해서다.
        }
        //현재 인덱스를 스택에 넣기
        st.push(i);
    }
    //스택이 빌때까지 반복 ->끝까지 살아남은(주식이 떨어지지 않은) element들.
    while (!st.empty()) {
        //위에서 특정위치에 이미값을 넣었으므로 pushback이나 insert로하면 안된다.
        //뒤에서부터 넣어야하므로 size-1 에서 top값을 빼준다.
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}