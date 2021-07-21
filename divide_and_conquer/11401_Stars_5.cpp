#include <iostream>
#include <string>
using namespace std;

#define modulo 1000000007

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
	int input1, input2;
	cin >> input1 >> input2;
	
	unsigned long long A = 1, B = 1, temp = 1; //위에서 정리한 A, B
// 	A (n!)연산
	for(int i = 1; i <= input1; i++){
		A = (A * i) % modulo;
	}
	
// 	B (n-r)! 연산
	for(int i = 1; i <= input1 - input2; i++){
		B = (B * i) % modulo;
	}
// 	temp(r!) 연산
	for(int i = 1; i <= input2; i++){
		temp = (temp * i) % modulo;
	}
// 	B , temp 연산 합치기
	B = (B * temp) % modulo;
	
	
	string binary = to_binary(modulo - 2); // modulo의 2진수를 저장.
	unsigned long long cache[32];	//DP를 위한 arr
	for(int i = 0; i < 32; i ++)
		cache[i] = 0;
	cache[binary.size() - 1] = B % modulo;// 반복문 실행을 위한 background
// 	각 제곱 별로 나머지 계산
	for(int i = binary.size() - 2 ;i >= 0; i--)
		cache[i] = (cache[i+1] * cache[i+1]) % modulo;
	
	
// 	이진법중 1인 것들의 나머지만 곱해주기.
	unsigned long long ans = 1;
	for(int i = binary.size() - 1; i >=0; i --){
		if(binary[i] == '1')	ans = ans * cache[i];
		if(ans > modulo)	ans = ans % modulo;
	}
	
	cout << (ans * A ) % modulo << '\n';
	
	return 0;
}

// 곱셈의 역원과 페르마의 소정리를 이용하는 문제.
// 곱셈의 역원이랑 a * a^-1 = 1 (mod m)을 만족시키는 a^-1을 찾는 것이다.
// 역원은 a와 m이 서로수인 경우에만 존재한다.
// 페르마의 소정리란 a^m = a (mod m) ※단 a와 m은 서로소
// a^m-1 = 1 (mod m)
// a^m-1 = a * a^-1
// a^m-2 = a^-1
// 이항정리에서 nCr이라면, n! / ((n-r)! * r!)
// n! = A, ((n-r)! * r!) = B라고 한다면, 
// A / B = x (mod m) 페르마의 소정리를 이용하면,
// B = B^m인데, B^-1은, B^m-2이므로, 
// A * B^m-2 = x 
///////////////////////////////////////
////결국 구하고자 하는건 A * B^m-2(mod m)이다////
///////////////////////////////////////