#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
void binarySearch(int start, int end, int wantToFind){
	if(start > end){
		cout << 0 << '\n';
		return;
	}
	int mid = (start + end) / 2;
	if(arr[mid] == wantToFind){	//맞는 숫자를 찾은 경우
		cout << 1 << '\n';
		return ;
	}
	else{
		if(arr[mid] < wantToFind){	// 찾는 숫자가 현재 선택한 값보다 큰 경우
			binarySearch(mid + 1, end, wantToFind);
		}
		else{	//찾는 숫자가 현재 선택한 값보다 작은 경우
			binarySearch(start, mid - 1, wantToFind);
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int firstInput;
	cin >> firstInput;
	for(int i = 0 ; i < firstInput; i++){
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	int secondInput;
	cin >> secondInput;
	sort(arr, arr + firstInput);
	for(int i = 0 ; i < secondInput; i++){
		int temp;
		bool finded = false;
		cin >> temp;
		binarySearch(0, firstInput - 1, temp);
	}
	return 0;
}