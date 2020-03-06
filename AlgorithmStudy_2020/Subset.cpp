/*#include <iostream>
#include <vector>

using namespace std;
//부분집합 처리하는 함수
void search(int k);
//집합의 원소의 개수
int n;
//부분집합
vector <int> subset;
int main() {
	cout << "원소의 개수를 입력하세요" << endl;
	cin >> n;
	search(0);
	return 0;
}


void search(int k) {
	if (k == n + 1) {
		//부분집합 처리
		cout << '{';
		for (int i = 0;i < subset.size();i++){
			if (i == subset.size() - 1)
				cout << subset[i] ;
			else
				cout << subset[i] << ',';
		}
		cout << '}'<<endl;
		return;
	}
	else {
		//k를 부분집합에 포함시킨다
		subset.push_back(k);
		search(k + 1);
		subset.pop_back();
		//k를 부분집합에 포함시키지 않는다
		search(k + 1);
	}
}
*/
/* 
	해맸던 이유: subset의 사이즈만큼만 부분집합을 처리할때 for문이 돌아야하는데
				 n으로 설정해서 무작정 원 집합의 원소의 개수만큼 돌게 한것이 문제였음.
				 'element의 개수'라는 개념에 사로잡혀서 '어떤 vector'의 개수인지를 파악하지 못한것이 흠 
*/