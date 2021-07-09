#include <iostream>

using namespace std;

int cache[1002][1002];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	int input1;
	int input2;
	cin >> input;
	for(int i = 0 ; i < input; i++){
		cin >> input1 >> input2;
		cache[0][1] = 1;
	
		if(input2 > input1){
			int temp = input2;
			input2 = input1;
			input1 = temp;
		}

		for(int i = 1; i < input1 + 2; i++){
			for(int j = 1; j < input1 + 2; j++){
				cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]);

			}
		}

		cout << cache[input1][input2 + 1] << '\n';
	}
	
	
	
	return 0;
}