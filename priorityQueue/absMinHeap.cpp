#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > absMinHeap;
    // priority queue는 priority queue<넣을 자료형, 구현할 자료구조 (벡터, 디큐), 비교연산자(greater (min heap), less(max heap)) >
    cin >> num;
    for (int i = 0 ; i < num; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(absMinHeap.empty()){
                cout << 0 << '\n';
                continue;
            }
            else{
                cout << absMinHeap.top().second << '\n';
                absMinHeap.pop();
                continue;
            }
        }
        else{
            absMinHeap.push(make_pair(abs(temp), temp));
            continue;
        }
    }

	return 0;
}