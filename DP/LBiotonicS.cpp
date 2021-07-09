#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	변수 선언 및 초기화
	int input;
	vector <int> inputSequence;
	int increasingCache[1000];
	int decreasingCache[1000];
	int maximumLength = 0;
	
// 	입력 받기
	cin >> input;
	for(int i = 0; i < input; i++){
		int temp;
		cin >> temp;
		inputSequence.push_back(temp);
	}
// 	증가하는 수열 탐색
	for(int i = 0; i < input; i++){
		int & targetCache = increasingCache[i] = 1;
		for(int j = 0; j < i; j++){
			if(inputSequence[i] > inputSequence[j])
				targetCache = max(targetCache, increasingCache[j] + 1);
		}
	}
// 	감소하는 수열 탐색
	for(int i = input-1; i > -1; i--){
		int & targetCache = decreasingCache[i] = 1;
		for(int j = input-1; j > i; j--){
			if(inputSequence[i] > inputSequence[j])
				targetCache = max(targetCache, decreasingCache[j] + 1);
		}
	}
	
	for(int i = 0; i < input; i++)
		maximumLength = max(maximumLength, increasingCache[i] + decreasingCache[i] - 1);
	
	cout << maximumLength << '\n';
	return 0;
}


// 중간에 있는 4를 기준으로 보자..
// 4에서 봐야할 것들이 뭘까.
// 4는 증가되는 쪽에 속하는지, 감소되는 쪽에 속하는지.
// 감소되는 쪽이라면, 그 전께 자기보다 큰거일거고,  다음이 자기보다 작은 거겠지.
// 큰 쪽이라면, 그 전께 자기보다 작은 것, 다음이 자기보다 큰 것일 것이다.
// 근데 각 숫자별로 이걸 선택한다면, 증가 감소 증가 감소되면서 길이가 유지가 될텐데..
// 이러면 그전 숫자가 감소하기 시작했다면, 쭉 감소해야 된다는 거지.
// 그러면 그 감소되는 시점을 정하는게 중요하다는건데.
// 그렇다면, 증가되는 숫자들을 적고, 나를 기준으로 감소했을 때, 총 길이가 어떻게 나오는지를 알면 되겠다.

// 그럼 각각의 수열을 기준으로 앞에서 한 번, 뒤에서 한번 증가 감소로 나눠서 DP를 돌리면 어떨까 한번 봐보자


// 1 5 2 1 4 3 4 5 2 1

// 	증가	감소	바이토닉길이
// 1	1	1	1	
// 5	2	5	6
// 2	2	2	3
// 1	1	1	1
// 4	3	4	6
// 3	3	3	5
// 4	4	3	6
// 5	5	3	7
// 2	2	2	3
// 1	1	1	1
// 	Got it!!