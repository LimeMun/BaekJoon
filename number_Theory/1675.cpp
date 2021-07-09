#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	int sum = 0;
	for(int i = 1 ; i < input + 1; i++){
		int temp = i;
		while(temp % 5 == 0){
			sum++;
			temp = temp / 5;
		}
	}
	
	cout << sum << '\n';
	
	return 0;
}