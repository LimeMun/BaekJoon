#include <iostream>

using namespace std;

// 5, 25, 125의 배수인지 해서 +1, +2, +3 따로 해주지 않아도 되는 이유는, 5를 기준으로 카운팅할 때, 25도 포함 되므로, 25를 셀때 +2를 안해줘도 된다. 즉, 5를 곱하면서 개수만 더해주면 된다.
// long long으로 해줘야하는 이유는, 숫자가 20억이니까 int의 범위에서는 해결을 하지 못한다!!!!!!!
int count(long long object, long long number){
	long long sum = 0;
	for(long long i = number; i <= object; i *= number)
		sum += object / i;
	return sum;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long input1, input2;
	cin >> input1 >> input2;
	
	long long countFive = count(input1, 5) - count(input2, 5) - count(input1 - input2, 5);
	long long countTwo = count(input1, 2) - count(input2, 2) - count(input1 - input2, 2);
	
	cout << min(countFive, countTwo) <<'\n';
	
	return 0;
}