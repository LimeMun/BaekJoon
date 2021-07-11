#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	while(true){
		string inputString;
		stack <int> cache;
		bool flag = true;
// 		cin getline은 \n은 분리해서 받고 다음 입력버퍼에 남기므로 cin.ignore로 지워야한다.
		getline(cin, inputString);
		if(inputString == ".")
			break;
		for(int i = 0; i < inputString.size(); i++){
			if(inputString[i] == '(')
				cache.push(1);
			else if(inputString[i] == '[')
				cache.push(2);
			else if(inputString[i] == ')'){
				if(cache.empty() || cache.top() != 1){
					flag = false;
					break;
				}
				else
					cache.pop();
			}
			else if(inputString[i] == ']'){
				if(cache.empty() || cache.top() != 2){
					flag = false;
					break;
				}
				else
					cache.pop();
			}
		}
		if(!cache.empty())
			flag = false;
		if(flag)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}