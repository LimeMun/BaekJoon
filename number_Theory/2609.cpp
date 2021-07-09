#include <iostream>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	입력 받기
	int num1;
	int num2;
	int divisor= 2;
	int multipleOfDivisor = 1;
	cin >> num1 >> num2;
	while(true){
		
		if((divisor > num1) && (divisor > num2))
			break;
		
		if((num1 % divisor == 0)&& (num2 % divisor == 0)){
			num1 = num1 / divisor;
			num2 = num2 / divisor;
			multipleOfDivisor *= divisor;
		}
		else
			divisor += 1;
	}
	
	cout << multipleOfDivisor << '\n' << multipleOfDivisor * num1 * num2 << 'n';
	return 0;
}