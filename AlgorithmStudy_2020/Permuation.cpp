/*#include <iostream>
#include <vector>

using namespace std;

void search();
int n;
vector <bool> chosen;
vector <int> permutation;
int main() {
	cout << "원소의 개수를 입력하세요" << endl;
	cin >> n;
	chosen.resize(n + 1);
	chosen[1] = false;
	search();
	return 0;
}

void search() { 
	if (permutation.size() == n) {
		//순열을 처리
		cout << "[";
		for (int i = 0; i < permutation.size(); i++) {
			cout << permutation[i];
		}
		cout << "]" << endl;
		return;
	}
	else {		
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}
*/
/*
	해맸던 이유: 일단 아무리 생각해도 c++에서 배열의 원소의 개수를 나중에 알려주는 방법이
				 떠오르지 않았다. 
				 '원소의 개수 -> 배열 선언' 은 지원해도 '배열 선언-> 원소의 개수 -> 배열 메모리 할당' 은 
				 지원하지 않는다.
				 그래서 그냥 chosen 쪽을 vector로 바꾸었다. 나중에 resize method 를 이용하면 되니깐.
				 그리고 chosen[1]를 false로 해야 알고리즘상 1을 선택할텐데 그걸 착각했다.
	Algorithm Point : 선택한다 안했다를 bool 배열로 확인한다는 것이 참신하다. 
	                  그리고 재귀는 굳이 말하지않아도..
*/