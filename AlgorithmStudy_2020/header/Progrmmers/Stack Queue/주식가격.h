#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int current_price = prices.at(i);
		int cnt = 0;
		//�ڱ� �ڽź��� �������μ� �ٷ� �ڱ��ڽŶ��� 1�ʸ� ����
		for (int j = i; j <= prices.size(); j++) {
			//������(j=prices.size())���� �Դٸ� �� �������ɷ� ����.
			//�̶��� �ð��� �帥�� �ƴϹǷ� cnt-1�� ���ش�.
			if (j == prices.size()) {
				answer.push_back(cnt-1);
				break;
			}
			int comp_price = prices.at(j);
			//�ֽ� ������ �������ٸ� answer vector�� cnt ���� push
			if (comp_price < current_price) {
				answer.push_back(cnt);
				break;
			}
			//�������� �ʾҴٸ� cnt�� ����
			else cnt++;
		}
	}
	return answer;
} 

//https://mungto.tistory.com/6 ���� ->stack�̿�
vector<int> solution2(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;
    for (int i = 0; i < size; i++) {
        //������ ��������ʰ� ���ø����� ���� ���簪���� ũ�ٸ�
        //-> ������ �������ٸ�
        while (!st.empty() && prices[st.top()] > prices[i]) {
            //������ ���������Ƿ� i - ���� �������� ����
            answer[st.top()] = i - st.top();
            //������
            st.pop();
            //�ݺ����� ����: ������ �������� �����Ǿ������
            //���簪���� ��������Ƿ� 1�����̾� �־��ֱ� ���ؼ���.
        }
        //���� �ε����� ���ÿ� �ֱ�
        st.push(i);
    }
    //������ �������� �ݺ� ->������ ��Ƴ���(�ֽ��� �������� ����) element��.
    while (!st.empty()) {
        //������ Ư����ġ�� �̹̰��� �־����Ƿ� pushback�̳� insert���ϸ� �ȵȴ�.
        //�ڿ������� �־���ϹǷ� size-1 ���� top���� ���ش�.
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}