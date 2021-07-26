#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for(int i = 0 ; i < testCase; i++){
		string inputFunc;	// 실행할 함수.
		string inputListString;	//입력받는 배열이 문자열으로 들어으므로 입렫받기.
		int listNumCount;	// 배열의 개수.
		deque <int> list;
		cin >> inputFunc >> listNumCount >> inputListString;	// 함수, 수의개수, 수들을 입력 받기.
		int count, start, end = 0;
// 		문자열을 파싱하는 함수.
		for(int j = 0; j < inputListString.size(); j++){
			if(inputListString[j] == ',' || inputListString[j] == '[' || inputListString[j] == ']'){
				if(start !=0 && end != 0){
					int temp = stoi(inputListString.substr(start, end - start + 1));
					list.push_back(temp);
				}
				if(inputListString[j] == ']')
					break;
				start = j + 1;
				continue;
					
			}
			else if(inputListString[j] >= 48 && inputListString[j] <= 57){
				end = j;
				continue;
			}
		}
// 		함수를 실행하는 부분, Reverse, delete 기능을 수행한다.
		bool isThatReverse = false;
		bool isError = false;
		for(int j = 0 ; j < inputFunc.size(); j++){	//함수를 실행.
			if(inputFunc[j] == 'R'){	//Reverse가 나온다면, 서로 flip해주기.
				if(isThatReverse)	isThatReverse = false;
				else	isThatReverse = true;
			}
			if(inputFunc[j] == 'D' ){	//버리는 경우, Reverse인지 판단.
				if(list.size() == 0){
					isError = true;
					break;
				}
				if(isThatReverse)	list.pop_back();
				else	list.pop_front();
			}
		}
// 		출력하는 부분, 리버스인지 아닌지 판단해준다음 출력한다.
// 		만약 에러가 난 경우 바로 캐치해준다.
		if(isError){
			cout << "error" << '\n';
			continue;
		}
// 		정상적인 출력부분
		cout << '[';
		if(isThatReverse){
			while(!list.empty()){
				cout << list.back();
				list.pop_back();
				if(list.empty()){
					break;
				}
				else	cout << ',';
			}
		}
		else{
			while(!list.empty()){
				cout << list.front();
				list.pop_front();
				if(list.empty()){
					
					break;
				}
				else	cout << ',';
			}
		}
		cout << ']' << '\n';

	}

	return 0;
}