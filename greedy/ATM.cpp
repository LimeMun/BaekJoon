#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	변수 설정
	int input;
	int withdrawTime [1000];
	int partSum [1000];
// 	입력 받기
	cin >> input;
	for(int i = 0; i < input; i++)
		cin >> withdrawTime[i];
	
	sort(withdrawTime, withdrawTime + input);
// 	sort한 후에, 부분합을 구한 후, 최종적으로 모든 합을 구하기.
// 	default 설정
	partSum[0] = withdrawTime[0];
	int sum = partSum[0];
	for(int i = 1; i < input; i++){
		partSum[i] = partSum[i-1] + withdrawTime[i];
		sum = sum + partSum[i];
	}
	
	cout << sum << '\n';
	
	return 0;
}