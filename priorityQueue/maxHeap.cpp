#include <iostream>
#include <vector>
using namespace std;

int arr [100000];
int heapIndex = 0;

void swap(int * a, int * b){
    int temp;
    temp = * a;
    * a = * b;
    * b = temp;
}

void heap_Push(int data){
    int index = ++heapIndex;
    arr[index] = data;
    while((index != 1) && (data > arr[index / 2])){
        swap(&arr[index], &arr[index / 2]);
        index = index / 2;
    }
}

void heap_Pop(){
    // 맽 끝 값과 루트노드를 바꾼 후 삭제하는 과정.
    if(heapIndex == 0){
        cout << 0 << '\n';
        return;
    }
    cout << arr[1] << '\n';
    arr[1] = arr[heapIndex--];
// 최대 heap을 다시 만드는 과정
    int parent = 1, child;
    while(1){
        child = parent * 2;
        if((child + 1 <= heapIndex) && (arr[child + 1] > arr[child]))   child++;
        if((child > heapIndex) || (arr[parent] > arr[child]))   break;
        swap(&arr[parent], &arr[child]);
        parent = child;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 0 ; i < num; i++){
        int temp;
        cin >> temp;
        if(temp == 0)   heap_Pop();
        else    heap_Push(temp);
    }
	return 0;
}