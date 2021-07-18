#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	while(true){
		bool isBreak = false;
		cin >> input;
		if(input == "0")	break;
		for(int i = 0; i < input.size() / 2; i++){
			if(input[i] != input[input.size() - 1 - i]){
				cout << "no" << '\n';
				isBreak = true;
				break;
			}
		}
		if(!isBreak)
			cout << "yes" << '\n';

	}
	return 0;
}