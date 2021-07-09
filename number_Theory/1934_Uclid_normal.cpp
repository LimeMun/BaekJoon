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
// 		큰 수를 나눈 나머지를 구해야하므로, 큰 수를 찾아서 Swap
		if(num2 > num1){
			int temp;
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int remain;
		int tempnum1 = num1;
		int tempnum2 = num2;
		while(tempnum2 != 0){
			remain = tempnum1 % tempnum2;
			tempnum1 = tempnum2;
			tempnum2 = remain;
		}
		cout << num1 * num2 / tempnum1 << '\n';
	}
	return 0;
}