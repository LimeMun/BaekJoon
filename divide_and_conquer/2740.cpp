#include <iostream>

using namespace std;


int row [100][100];
int column [100][100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rowInput1, rowInput2;
	cin >> rowInput1 >> rowInput2;
	for(int i = 0; i < rowInput1; i++){
		for(int j = 0 ; j < rowInput2; j++){
			int temp;
			cin >> temp;
			row[i][j] = temp;
		}
	}
	int columnInput3, columnInput4;
	cin >> columnInput3 >> columnInput4;
	for(int i = 0; i < columnInput3; i++){
		for(int j = 0 ; j < columnInput4; j++){
			int temp;
			cin >> temp;
			column[i][j] = temp;
		}
	}
	int matrix[rowInput1][columnInput4];//행렬 곱셈 배열 선언
	for(int i = 0 ; i < rowInput1 ; i++){
		for(int j = 0 ; j < columnInput4; j++){
			matrix[i][j] = 0;
		}
	}	
	
	for(int i = 0 ; i < rowInput1; i++){
		for(int j = 0 ; j < columnInput4; j++){
			for(int k = 0 ; k < rowInput2; k++){
				matrix[i][j] +=row[i][k] * column[k][j];
			}
		}
	}
	
	for(int i = 0 ; i < rowInput1 ; i++){
		for(int j = 0 ; j < columnInput4; j++){
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}

	
	return 0;
}