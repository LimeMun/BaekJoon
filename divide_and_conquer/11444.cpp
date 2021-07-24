#include <iostream>
#include <string>
#include <vector>
using namespace std;
// unsigned long long 은 8바이트로, 64bit로 2의 64제곱까지 나타낼 수 있다.
unsigned long long remain = 1000000007;
unsigned long long B;	// 제곱수 입력받기.
unsigned long long originMatrix[2][2]; // 처음 입력을 받는 matrix
unsigned long long cacheMatrix[2][2];	// 제곱된matrix를 저장할 matrix
unsigned long long answerMatrix[2][2];	// 정답을 저장할 matrix

// 10진법 숫자를 2진법으로 변환하는 함수
string to_binary(unsigned long long num){
	string s = "";
	while(num > 0){
		if(num % 2 == 1)
			s = "1" + s;
		else	s = "0" + s;
		num = num / 2;
	}
	return s;
}


void multiplyMatrix(unsigned long long arr1[][2], unsigned long long arr2[][2]){
	unsigned long long tempMatrix[2][2] = {0, };	// 곱셈을 수행할 matrix
	for(int i = 0 ; i < 2 ; i++){	//행렬 곱셈
		for(int j = 0 ; j < 2; j++){
			for(int k = 0; k < 2; k++){
				tempMatrix[i][j] += arr1[i][k] * arr2[k][j];
				tempMatrix[i][j] = tempMatrix[i][j] % remain;
			}
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			arr1[i][j] = tempMatrix[i][j];
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> B; // 행렬 크기와 제곱 수 입력 받기
	
	 // 행렬 선언 및 입력받기.
	originMatrix[0][0] = 1;
	originMatrix[0][1] = 1;
	originMatrix[1][0] = 1;
	originMatrix[1][1] = 0;
	
	string binary = to_binary(B);
// 	단위 행렬(특정 행렬과 단위 행렬을 곱하면 특정행렬이 나옴)
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			answerMatrix[i][i] = 1; // 단위행렬 셋팅
			cacheMatrix[i][j] = originMatrix[i][j]; // cacheMatrix 셋팅
		}
	}
// 	홀수라면, answerMatrix에 originMatrix를 곱해주기.
	if(binary[binary.size() - 1] == '1'){
		multiplyMatrix(answerMatrix, originMatrix);
	}
	
// 	2진법을 따라가면서, answerMatrix에 cacheMatrix를 곱해주기.
	for(int i = binary.size() - 2; i >= 0; i--){
		multiplyMatrix(cacheMatrix, cacheMatrix);
		if(binary[i] == '1'){
			multiplyMatrix(answerMatrix, cacheMatrix);
		}
	}
// 	출력하는 부분.
	cout << answerMatrix[0][1] << '\n';
	return 0;
}