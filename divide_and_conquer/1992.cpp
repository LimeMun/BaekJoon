#include <iostream>

using namespace std;

int arr[64][64];
void quadTree(int countingToFind, int y, int x){
	if(countingToFind == 1){
		cout << arr[y][x]; //들어있는 숫자의 개수를 카운트
		return ;
	}
// 	0만 있는지, 1만 있는지, 둘다 있는 지 체크하기 위한 flag
	bool isOne = false;
	bool isZero = false;
	bool isFail = false;
// 	정해진 범위내를 돌면서, 0과 1을 체크하는 반복문, 0과 1이 동시에 발견된 경우 isFail flag가 true가 되고 반복문이 멈춘다.
// 	반복문 위치를 정해줄때는 시작위치도 같이 더해줘야한다!!
	for(int i = y; i < y + countingToFind; i++){ 
		for(int j = x; j < x + countingToFind; j++){
			int value = arr[i][j];
			if(value == 0)	isZero = true;
			else if (value == 1)	isOne = true;
			
			if(isOne && isZero){
				isFail = true;
				break;
			}
		}
		if(isFail)
			break;
	}
	if(isFail){
		cout << '(';
		quadTree(countingToFind / 2, y, x);
		quadTree(countingToFind / 2, y, x + countingToFind / 2);
		quadTree(countingToFind / 2, y + countingToFind / 2, x);
		quadTree(countingToFind / 2, y + countingToFind / 2, x + countingToFind / 2);
		cout << ')';
		return;
	}
	if(isZero){
		cout << 0;
		return;
	}
	if(isOne){
		cout << 1;
		return;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input; // 몇칸인지 입력받고, matrix 받기.
	for(int i = 0 ; i < input; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < input; j++){
			arr[i][j] = temp[j] - '0';
		}
	}
	quadTree(input, 0, 0);
	cout << '\n';
	
	return 0;
}