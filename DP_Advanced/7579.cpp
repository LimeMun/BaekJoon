#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10001]; // dp[i][j]는 i번째 앱까지 선택했을 때, j만큼의 비활성화 비용을 갖는 최대 메모리.
// 만약, 경우를 나눠보면

// 5 60
// 30 10 20 35 40
// 3 0 3 5 4
// 경우에 대해서는, 이런 식이 나오게 되는데
//  dp[i][j] = max(dp[i - 1][j - reactiveCost[i]] + appMem[i], dp[i - 1][j])
// 이 식을 말로 풀어서 해석하자면, 새로운 앱을 포함하는걸 기준으로한다면, 
// 지금 선택한 앱을 비활성화 한다면, 비활성화하기로한 앱 하나를 빼고, 지금 선택한 앱을 비활성화했을때의 최대 메모리  -> (dp[i - 1][j - reactiveCost[i]] + appMem[i])
// 지금 선택한 앱을 비활성화 하지 않는 경우, 같은 cost를 가지는 dp[i - 1][j]를 그대로 가져오는 것이다.
// 같은 비용을 썼을 떄, 많은 메모리를 확보할 수 있는 것을 선택하는 것이다.
// 그래서 비용을 기준으로 탐색해서, 확보하고자 하는 메모리 이상이 나오는 비용이 최소 비용이다.
// 몇번째앱\비용    0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15
// 0            0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
// 1            0       0       0       30      30      30      30      30      30      30      30      30      30      30      30      30
// 2            10      10      10      40      40      40      40      40      40      40      40      40      40      40      40      40
// 3            10      10      10      40      40      40      60      60      60      60      60      60      60      60      60      60
// 4            10      10      10      40      40      45      60      60      75      75      75      95      95      95      95      95
// 5            10      10      10      40      50      50      60      80      80      85      100     100     115     115     115     135
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int appNum, memCapacity;
    int maxCost = 0;
    int appMem[101];
    int reactiveCost[101];
    cin >> appNum >> memCapacity;
    for(int i = 1 ; i <= appNum; i++)    cin >> appMem[i];
    for(int i = 1 ; i <= appNum; i++){
        int temp;
        cin >> temp;
        reactiveCost[i] = temp;
        maxCost += temp;
    }
    //dp 계산 시작.
    for(int i = 1; i <= appNum; i++){
        int nowCost = reactiveCost[i];
        for(int j = 0; j <= maxCost; j++){
            if(j >= nowCost){
                dp[i][j] = max(dp[i - 1][j - nowCost] + appMem[i], dp[i - 1][j]);
                continue;
            }
            dp[i][j] = dp[i - 1][j];
        }
    }
    bool signal = false;
    for(int i = 0; i <= maxCost; i++){
        for(int j = 1 ; j <= appNum; j++){
            if(dp[j][i] >= memCapacity){
                cout << i << '\n';
                signal = true;
                break;
            }
        }
        if(signal)  break;
    }






	return 0;
}