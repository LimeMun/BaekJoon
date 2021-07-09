#include <iostream>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	입력 받기
	int input;
	int num1;
	int num2;
	cin >> input;
	for(int i = 0; i < input; i++){
		cin >> num1 >> num2;
		int divisor= 2;
		int multipleOfDivisor = 1;
		while(true){

			if((divisor > num1) && (divisor > num2))
				break;

			if((num1 % divisor == 0)&& (num2 % divisor == 0)){
				num1 = num1 / divisor;
				num2 = num2 / divisor;
				multipleOfDivisor *= divisor;
				continue;
			}
			else
				divisor += 1;
		}

		cout << multipleOfDivisor * num1 * num2 << '\n';
	}
	return 0;
}