#include <iostream>
#include <string>
using namespace std;


string to_binary(int num){
	string s = "";
	while(num > 0){
		if(num % 2 == 1)	s = "1" + s;
		else	s = "0" + s;
		num >>= 1; //쉬프르 연산
	}
	return s;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input1, input2, input3;
	cin >> input1 >> input2 >> input3;
	
	string binary = to_binary(input2); //B의 2진수를 저장.
	// cout << binary;
	unsigned long long cache[32];	//DP를 위한 arr
	cache[binary.size() - 1] = input1 % input3;// 반복문 실행을 위한 background
// 	각 제곱 별로 나머지 계산
	for(int i = binary.size() - 2 ;i >= 0; i--)
		cache[i] = (cache[i+1] * cache[i+1]) % input3;
	
// 	이진법중 1인 것들의 나머지만 곱해주기.
	unsigned long long ans = 1;
	for(int i = binary.size() - 1; i >=0; i --){
		if(binary[i] == '1')	ans = ans * cache[i];
		if(ans > input3)	ans = ans % input3;
	}
	
	cout << ans << '\n';
	
	return 0;
}