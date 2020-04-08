#include <bits/stdc++.h>

using namespace std;
//예외 클래스 작성
template <class T>
class Exception {
	private :
		T elemet;
	public:
		Exception(T element) {
			this.elemet = elemet;
		}
		T getElement() {
			return elemet;
		}
};
void coin1();
void coin2();
void coin3();
void MainCoin() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << "동전세기 문제중에 어떤 걸 고르시겠습니까?" << endl;
	cout << "1)가장 적은 수로 주어진 값을 맞출 때 얼마나 적은 수인지 알아내기" << endl;
	cout << "2)가장 적은 수로 주어진 값을 맞출때 그 값이 어떻게 만들어지는지 알아내기" << endl;
	cout << "3)주어진 동전들로 합 x를 만드는 경우의 수를 세는 문제" << endl;

	try {
		string choice;
		cin >> choice;
		if (choice != "1" && choice != "2" && choice !="3") throw choice;
		else if (choice == "1") coin1();
		else if (choice == "2") coin2();
		else coin3();
	}
	catch(string s){
		cout << "잘못된 입력"<<s<<"를 입력했습니다"<< endl;
	}
	cout << "동전세기 문제 끝!" << endl;
}
//가장 기본적인 동전문제
void coin1() {
	//Memoization
	int* value = new int[1000];

	cout << "몇개의 동전이 있습니까?" << endl;
	int n;
	cin >> n;
	cout << "동전의 가치를 입력하세요" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "얼마를 맞추고 싶습니까?" << endl;
	int object;
	cin >> object;
	//반복문을 통한 구현
	value[0] = 0;
	for (int x = 1; x <= object; x++)
	{
		value[x] = 2147483647;
		for (auto c : coins) {
			if (x - c >= 0) {
				value[x] = min(value[x], value[x - c] + 1);
			}
		}
	}
	cout << "필요한 동전의 수는 " << value[object-1] << "개 입니다." << endl;
}

//해답이 어떻게 구성되는지 알아보는 동전 문제
void coin2() {
	//Memoization
	int* value = new int[1000];
	//어떤 해답들이 들어가는지 알아보기 위한 배열
	int first[1000] = { 0, };
	
	cout << "몇개의 동전이 있습니까?" << endl;
	int n;
	cin >> n;
	cout << "동전의 가치를 입력하세요" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "얼마를 맞추고 싶습니까?" << endl;
	int object;
	cin >> object;
	//반복문을 통한 구현
	value[0] = 0;
	for (int x = 1; x <= object; x++) {
		value[x] = 2147483647;
		for (auto c : coins) {
			if (x - c >= 0 && value[x - c] + 1 < value[x]) {
				value[x] = value[x - c] + 1;
				first[x] = c;
			}
		}
	}
	cout << "최소 " << value[object] << "개의 동전을 이용해서 " << object << "를 맞출 수 있습니다." << endl;
	cout << "그리고 그 해의 조합은 {";
	while (object > 0) {
		cout << first[object]<<",";
		object -= first[object];
	}
	cout << "} 입니다." << endl;
}

//단순히 목표하는 숫자를 동전의 합으로 만들 수 있는  조합의 개수 구하기
void coin3() {
	//Memoization
	int* count = new int[1000]{ 0, };

	cout << "몇개의 동전이 있습니까?" << endl;
	int n;
	cin >> n;
	cout << "동전의 가치를 입력하세요" << endl;
	set<int> coins;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coins.insert(temp);
	}
	cout << "얼마를 맞추고 싶습니까?" << endl;
	int object;
	cin >> object;
	//반복문을 통한 구현
	count[0] = 1;
	cout << "\n";
	for (int x = 1; x <= object; x++) {
		for (auto c : coins) {
			if(x-c>=0) count[x] += count[x - c];
		}
	}
	cout << "합 " << object << "를 맞출 수 있는 조합은 총" << count[object] << "개 입니다." << endl;
}

/*
	문제점 1) 문제를 고르는 과정에서 다른 걸 입력했을 때 그냥 튕김 (Runtime Error)
			-> catch 문에서 ...때문에 반드시 무언가 변수를 넘겨줘야하는데 안 넘겨줘서 그렇다
			-> string으로 처리함 (나중에 int 형으로 type convert를 해야하나?)
			-> <해결완료>
		   2) 2번문제에서 first 배열을 출력하는 과정에서 무한 loop
			-> 0보다 크거나 '같다'로 처리 되어 있어서 그랬음
			-> 하지만 여전히 value[object -1] 이 주소값이 출력되는중,,,
			-> 사실 주소값이 아니라 내가 처음에 초기화한 매우 큰값
			-> base case 설정을 잘못했다! 근데 여전히 답이 틀리다!
			-> 3)과 같은 오류...
		   3) 마지막 문제 count[object-1]을 출력하면 주소값 출력
			-> 내가 배열을 설정하고 초기화를 안 한 문제 (항상 발생하지 계속 생각하자)
			-> 그런데 답이 틀리네??
			-> 아 count[obeject]가 정답이네... 기존 배열과 다르게 index=0 도 목표 금액이 0원으로 setting한 것이니깐..
			-> <해결 완료>
*/