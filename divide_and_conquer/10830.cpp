#include <iostream>
#include <string>
#include <vector>
using namespace std;
// unsigned long long 은 8바이트로, 64bit로 2의 64제곱까지 나타낼 수 있다.

int N;	// 행렬크기
unsigned long long B;	// 제곱수 입력받기.
unsigned long long originMatrix[5][5]; // 처음 입력을 받는 matrix
unsigned long long cacheMatrix[5][5];	// 제곱된matrix를 저장할 matrix
unsigned long long answerMatrix[5][5];	// 정답을 저장할 matrix

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


void multiplyMatrix(unsigned long long arr1[][5], unsigned long long arr2[][5]){
	unsigned long long tempMatrix[5][5] = {0, };	// 곱셈을 수행할 matrix
	for(int i = 0 ; i < N ; i++){	//행렬 곱셈
		for(int j = 0 ; j < N; j++){
			for(int k = 0; k < N; k++){
				tempMatrix[i][j] += arr1[i][k] * arr2[k][j];
				tempMatrix[i][j] = tempMatrix[i][j] % 1000;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			arr1[i][j] = tempMatrix[i][j];
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> B; // 행렬 크기와 제곱 수 입력 받기
	
	 // 행렬 선언 및 입력받기.
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> originMatrix[i][j];
		}
	}
	
	string binary = to_binary(B);
// 	단위 행렬(특정 행렬과 단위 행렬을 곱하면 특정행렬이 나옴)
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
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
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout <<  answerMatrix[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}