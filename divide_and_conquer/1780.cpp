#include <iostream>

using namespace std;

int colorPaper[2200][2200];
int counting[3];
void quadTree(int countingToFind, int y, int x){
	if(countingToFind == 1){
		counting[colorPaper[y][x] + 1]++; //들어있는 숫자의 개수를 카운트
		return ;
	}
// 	0만 있는지, 1만 있는지, 둘다 있는 지 체크하기 위한 flag
	bool isOne = false;
	bool isZero = false;
	bool isNegativeOne = false;
	bool isFail = false;
// 	정해진 범위내를 돌면서, 0과 1을 체크하는 반복문, 0과 1이 동시에 발견된 경우 isFail flag가 true가 되고 반복문이 멈춘다.
// 	반복문 위치를 정해줄때는 시작위치도 같이 더해줘야한다!!
	for(int i = y; i < y + countingToFind; i++){ 
		for(int j = x; j < x + countingToFind; j++){
			int value = colorPaper[i][j];
			if(value == 0)	isZero = true;
			else if (value == 1)	isOne = true;
			else if (value == -1)	isNegativeOne = true;
			
			if(isOne && isZero ||isOne && isNegativeOne || isZero && isNegativeOne){
				isFail = true;
				break;
			}
		}
		if(isFail)
			break;
	}
	if(isFail){
		quadTree(countingToFind / 3, y, x);
		quadTree(countingToFind / 3, y, x + countingToFind / 3);
		quadTree(countingToFind / 3, y, x + (countingToFind / 3) * 2);
		quadTree(countingToFind / 3, y + countingToFind / 3, x);
		quadTree(countingToFind / 3, y + countingToFind / 3, x + countingToFind / 3);
		quadTree(countingToFind / 3, y + countingToFind / 3, x + (countingToFind / 3) * 2);
		quadTree(countingToFind / 3, y + (countingToFind / 3) * 2, x);
		quadTree(countingToFind / 3, y + (countingToFind / 3) * 2, x + countingToFind / 3);
		quadTree(countingToFind / 3, y + (countingToFind / 3) * 2, x + (countingToFind / 3) * 2);
		return;
	}
	if(isZero){
		counting[1]++;
		return;
	}
	if(isOne){
		counting[2]++;
		return;
	}
	if(isNegativeOne){
		counting[0]++;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input; // 몇칸인지 입력받고, matrix 받기.
	for(int i = 0 ; i < input; i++){
		for(int j = 0; j < input; j++){
			int temp;
			cin >> temp;
			colorPaper[i][j] = temp;
		}
	}
	quadTree(input, 0, 0);
	cout << counting[0] << '\n' << counting[1] << '\n' << counting[2] << '\n';
	
	return 0;
}