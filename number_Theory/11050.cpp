#include <iostream>

using namespace std;

int cache[1002][1002];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input1;
	int input2;
	cin >> input1 >> input2;
	cache[0][1] = 1;
// 	각 열의 0번째는 배열의 범위를 벗어나므로, 식의 일반화를 위해서 0번째의 0을 삽입하였다.
// 	그로 인해, input이 주어질 때, 제일 마지막열의 맨 오른쪽 원소는 설정이 안되는 버그가 발생했고, +2를 해주면서, 버그를 해결하였다.
	
	// for(int i = 1; i < input1 + 1; i++){
	// 	for(int j = 1; j < input1 + 1; j++){
	// 		cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]) % 10007;
			
	// 	}
	// }
	
	for(int i = 1; i < input1 + 2; i++){
		for(int j = 1; j < input1 + 2; j++){
			cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]) % 10007;
			
		}
	}
	// for(int i = 0; i < input1 + 2; i++){
	// 	for(int j = 0; j < input1 + 2; j++){
	// 		cout << cache[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	cout << cache[input1][input2 + 1] << '\n';
	
	return 0;
}