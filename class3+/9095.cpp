#include <iostream>

using namespace std;
int dp[11]; // 간단한 점화식 풀이 방식이었다.
// dp문제라는 생각이 들면, 점화식 도출을 해보려고 노력해보도록 하자.
// 그냥 문제만봤을 때는 점화식이라는 생각이 안들었었다. ㅠㅠ 더 노력하자.

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int testCase;
    cin >> testCase;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 11; i++){
        dp[i] = dp[i - 3]+ dp[i - 2] + dp[i - 1];
    }
    while(testCase-- > 0){
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }

	return 0;
}