#include <iostream>

using namespace std;

int arr[20000002];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int firstInput;
	cin >>firstInput;
	for(int i = 0; i < firstInput; i++){
		int numInput;
		cin >> numInput;
		int temp = numInput + 10000000; // 음수를 생각해서 index로 변환
		arr[temp]++;
	}
	int secondInput;
	cin >> secondInput;
	for(int i = 0 ; i < secondInput; i++){
		int rqOutput;
		cin >> rqOutput;
		cout << arr[rqOutput + 10000000] << ' ';
	}
	return 0;
}