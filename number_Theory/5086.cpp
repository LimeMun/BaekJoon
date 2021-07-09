#include <iostream>
#include <vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	변수 initialization

	
// 	입력 받기
	while(true){
		int input1, input2;
		cin >> input1 >> input2;
		if(input1 == 0 && input2 == 0)
			break;
		if(input2 % input1 == 0)
			cout << "factor" << '\n';
		else if(input1 % input2 == 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}

	return 0;
}