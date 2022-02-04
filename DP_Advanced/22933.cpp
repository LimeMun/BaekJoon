#include <iostream>

using namespace std;
int coinNum;
int targetValue;

int coinArr[101];
int dp[10001] = {0, };

//원래는 처음에, dp[5] = dp[1] + dp[4] + dp[2] + dp[3] 을 해주려고 했다.
// 그러나 이 방법은 지금 이문제처럼 순서에 상관없이 선택하는 경우에는 다른경우에 포함되지 않으므로 다른 방식이 필요했다.
//  각 숫자별로 나타낼 수 있는 경우에 수를 넣는것이다.
// 만약 1 2 5 고, 찾고자하는 숫자가 10이라면 1로 dp 값을 업데이트 하면 이렇게된다. (dp는 나타낼 수 있는 경우의 수이다.)
// dp   1   2   3   4   5   6   7   8   9   10
//  1   1   1   1   1   1   1   1   1   1   1      
//  2   1   2   2   3   3   4   4   5   5   6
// 즉, 만약 지금 탐색하는 수가 t라면, dp[i] = dp[i] + dp[i - t]이다.
// 그 이유는, 이전에 나타낼 수 있던, dp의 개수에, 2를 추가하면 나타낼 수 있는 수의 개수를 추가해준거다.
// 결론은 내가 나타내려고 했던 방식에서, 좀 더 변형을 하면 풀 수 있던 방식이었다.

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> coinNum >> targetValue;
    for(int i = 1 ; i <= coinNum; i++){
        int temp;
        cin >> temp;
        coinArr[i] = temp;
    }
    dp[0] = 1;
    for(int i = 1 ; i <= coinNum; i++){
        for(int j = coinArr[i]; j <=targetValue; j++){
            dp[j] = dp[j] + dp[j - coinArr[i]];
        }
    }
    cout << dp[targetValue] << '\n';
    

	return 0;
}