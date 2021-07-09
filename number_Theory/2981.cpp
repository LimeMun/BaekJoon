#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int findGcd(int num1, int num2){
	
	if(num2 == 0)
		return num1;
	if(num2 > num1){
		int temp = num2;
		num2 = num1;
		num1 = temp;
	}
	int remain = num1 % num2;
	return findGcd(num2, remain);
}

// 이 문제의 핵심은, 모든 수를 나눠보는 것이 아니다. 주어진 수를 A, B 나머지를 R이라고 한다면,
// A = M * a(어떤 수) + R, B =  M * b(어떤 수) + R,
// A - B = M (A - b), 즉 M은 두 수를 뺀 것의 약수가 되므로, 모든 수들을  다른 수와 짝을 지어 뺀다음, 뺀 수들의  최대 공약수를 구한다.
// 마지막으로 최대 공약수의 약수를 구해주면 끝난다.
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	입력 받기
	int input;
	int num[100];
	vector <int> gcdNum;
	vector <int> ansVec;
	cin >> input;
	
	for(int i = 0; i < input; i++){
		cin >> num[i];
	}
// 	정렬 후, 각 숫자를 빼면서, 모두 최대공약수의 배수로 만들기.
	sort(num, num+input);
	for(int i = 1; i < input; i= i+2)
		gcdNum.push_back(num[i] - num[i-1]);
	
	if(input % 2 == 1)
		gcdNum.push_back(num[input-1] - num[input-2]);
// 	여러 수의 최대공약수를 구하기.
	int gcd = gcdNum[0];
	for(int i = 1; i < gcdNum.size(); i++){
		gcd = findGcd(gcd, gcdNum[i]);
	}
	
// 	최대공약수의 약수 구하기.
// 	여기서 핵심은, 최대공약수를 N이라 하면 N의 약수를 구하는데 O(N)의 시간이 필요 없다는 것이다. 약수는 특정 수를 기준으로 좌 우에 하나씩 존재하기 때문에, 특정 수의 제곱을 넘기 전까지만 계산해주면 된다. 
	for(int i = 1; i * i <= gcd; i++){
		if(gcd % i == 0){
// 			만약 같은 수가 중복해서 들어가는 경우.
			if(i == gcd / i){
				ansVec.push_back(i);
				continue;
			}
			else{
			ansVec.push_back(i);
			ansVec.push_back(gcd / i);
			}
		}
	}
// 	수를 무작위로 넣으면서, 정렬이 되지 않았으므로 정렬.
	sort(ansVec.begin(), ansVec.end());
	
	for(int i = 1 ; i < ansVec.size(); i++)
		cout << ansVec[i] << '\n';
	
	return 0;
}