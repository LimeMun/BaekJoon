// #include <iostream>
// using namespace std;

// bool isItprime(int number){
// 	if(number <= 1)
// 		return false;
// 	if (number == 2)
// 		return true;
	
// 	//제곱근찾기 불필요한 for문을 돌릴필요가 없었음, 제곱수를 구하고 구간을 나누는 것이 아니라, 제곱수를 구하는 과정에서 소수를 구하면 됐다.
// 	for(int i = 2; i*i <= number; i++){
// 		if(number % i == 0)
// 			return false;
// 	}
// 	return true;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int num;
// 	while(true){
// 		cin >> num;
// 		int count = 0;
// 		if (num == 0)
// 			break;
// 		for(int i = num+1 ; i < 2 * num + 1; i++){
// 			if(isItprime(i) == true)
// 				count++;
// 		}
// 		cout << count << '\n';
// 	}

// 	return 0;
// }