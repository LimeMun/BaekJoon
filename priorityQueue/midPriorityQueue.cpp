#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    priority_queue < int , vector<int>, less <int> > maxheap;
    priority_queue < int , vector<int>, greater <int> > minheap;
    int mid;
    int num;
    cin >> num;
    for(int i = 1 ; i < num + 1; i++){
        int temp;
        cin >> temp;
        // 첫번째 수는 바로 미드에 삽임
        if(i == 1){
            mid = temp;
            cout << mid << '\n';
            continue;
        }
        // mingheap, maxheap 중 어디에 삽입할 지를 mid 값을 기준으로 결정한다.
        if(temp > mid)  minheap.push(temp);
        else    maxheap.push(temp);
        // 넣은 다음 홀수번째 마다 정렬한다. (홀수번째 마다 정렬하는 이유는, 그 때마다 균형을 맞춰줘야하기 때문이다. 짝수일때는  size가 큰 heap의 top값과 미드 값을 비교해준다.)
        if(i % 2 == 1){
            if(minheap.size() > maxheap.size()){
                maxheap.push(mid);
                mid = minheap.top();
                minheap.pop();
            }
            else if(maxheap.size() > minheap.size()){
                minheap.push(mid);
                mid = maxheap.top();
                maxheap.pop();
            }
            // 둘의 크기가 같을 경우에는 그냥 출력.
            cout << mid << '\n';
        }
        else{
            if(minheap.size() > maxheap.size()) cout << min(minheap.top(), mid) << '\n';
            else    cout << min(maxheap.top(), mid) << '\n';
        }
    }
	return 0;
}