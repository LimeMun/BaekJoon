#include <iostream>
#include <cmath>
using namespace std;
int weightNum; // 추의 개수
int weightArr[31]; // 추의 무게를 저장하는 Arr
bool dp[31][15001]; // dp[i][w]는, i번까지의 추를 쓸 때, w의 무게를 가진 저울을 만들어 낼 수 있느냐.이다.

// 그러니까 dp문제인데, 추를 어디쪽에 추가하냐의 문제였다.
// 1, 추를 구슬쪽에 추가할지, 2. 추를 추쪽에 추가할지, 3. 추를 추가하지 말지. 이 세가지를 각 추를 놓을때마다 고민해야 되는 것이다.
// 그리고 만약, 추를 추가할 수 없는 경우. 
// 1. 추의 개수를 넘어선 경우, 2. 이미 그 값이 존재하는 경우. 2332같은 경우, 01번, 23번으로 둘다 dp[4][5]의 값을 만들 수 있다.
// 그리고 solve(0,0)을 넣음으로서, 만들어 질 수 있는 모든 값들을 모두 dp내에 true를 넣어준다.
// 그리고 마지막에, 찾고자 하는 값이 있으면 Y를 리턴해준다.
// 그리고 dp[추의 전체 개수][테스트할 구슬의 무게]인 이유는, 물론, 추 전체를 쓰지 않고도 구슬의 무게를 나타날 수도 있지만, 어차피 추 전체로 하더라도, 추를 추가하지 않는 경우로 계속 같은 무게는 유지되고 추의 개수는 증가하게 할 수 있으니, 위 방법으로 구하는게 규칙성을 가지게 값을 구할 수 있는 방법이다.

void solve(int weightIndex, int weight){
	if(weightIndex > weightNum || dp[weightIndex][weight])	return;
	dp[weightIndex][weight] = true;
	solve(weightIndex + 1, (weight + weightArr[weightIndex])); // 추를 구슬 반대편에 추가하는 경우.
	solve(weightIndex + 1, abs(weight - weightArr[weightIndex])); // 추를 구슬 쪽에 추가하는 경우.
	solve(weightIndex + 1, weight); // 추를 추가하지 않는 경우.

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> weightNum;
	for(int i = 0 ; i < weightNum; i++)	cin >> weightArr[i];
	solve(0, 0); // dp값을 모두 채워준다.

	int testCase;
	cin >> testCase;
	for(int i = 0 ; i < testCase; i++){
		int testNum;
		cin >> testNum;
		if(testNum > 15000)	cout << 'N' << ' ';
		else if(dp[weightNum][testNum])	cout << 'Y' << ' ';
		else	cout << 'N' << ' ';
	}

	return 0;
}