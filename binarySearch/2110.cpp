#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, C;
    vector <int> gongyuArr;
    cin >> N >> C;
    for(int i = 0 ; i < N; i++){
        int temp;
        cin >> temp;
        gongyuArr.push_back(temp);
    }
    sort(gongyuArr.begin(), gongyuArr.end());
    int low = 1, high = gongyuArr.back(); // 최소 거리는 1이므로 low를 1로 설정해줘야 한다.
    int maxLength = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        int prevGongyu = 0;
        int cnt = 1;
        for(int i = 1; i < N; i++){
            if(gongyuArr[i] - gongyuArr[prevGongyu] >= mid){
                prevGongyu = i;
                cnt++;
            }
        }
        
        if(cnt >= C){
            maxLength = max(maxLength, mid);
            low = mid + 1;
            continue;
        }
        else{
            high = mid - 1;
            continue;
        }
    }
    cout << maxLength << '\n';


	return 0;
}
//이 문제의 핵심 논지는, 가장 가까운 공유기 사이의 최대 거리를 계산하기 위해서, 각 공유기의 최소 거리를 mid로 잡고 parametric Search를 이용하여 개수가 맞다면 최소거리를 증가, 아니라면 최소거리를 감소시키는 방향으로 구해서 공유기의 최소 거리의 최대값을 구하는 것이다.