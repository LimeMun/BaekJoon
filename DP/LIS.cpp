#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 	LIS의 기본적인 알고리즘
// 	A. 내가 타겟으로 잡은 숫자를 기준으로 자기의 인덱스 숫자보다 낮은 애들을 기준으로 최대 길이를 구한다.
// 	B. 이전 인덱스에서는 각자의 최대길이가 저장되어있을 것이므로, 타겟 인덱스의 최대 길이는 자기보다 작은 숫자를 가진 인덱스 중에서 최대 길이에서 +1 한 것이다.
// 	이것을 바탕으로 코드를 짜보자.

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cache[1000];
	vector<int> sequence;
// 	변수 생성 및 초기화
	int input;
	
// 	수열의 개수 입력 받기
	cin >> input;
// 	수열 입력받기
	for(int i = 0; i < input; i++){
		int inputNum;
		cin >> inputNum;
		sequence.push_back(inputNum);
	}
// 	정말,, for문으로 짜기는 쉬운데, 재귀함수로 짜는게 너무 어렵다.. 특정한 규칙을 정해서 재귀로 짤 수 있도록 노력해봐야겠다. 
	int maximum = 0;
	for(int i = 0; i < input; i++){
		int & ret = cache[i] = 1;
		for(int j = 0; j < i; j++){
			if(sequence[i] > sequence[j])
				ret = max(ret, cache[j] + 1);
		}
		maximum = max(maximum, ret);
	}
	
	cout << maximum << '\n';
	

	return 0;
}