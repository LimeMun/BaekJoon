#include <iostream>

using namespace std;

int minHeapArr[100000];
int minHeapIndex = 0;

void swap(int * a, int * b){
    int temp;
    temp = * a;
    * a = * b;
    * b = temp;
}

void minHeap_push(int data){
    int tempIndex = ++minHeapIndex;
    minHeapArr[minHeapIndex] = data; 
    while((tempIndex != 1) && minHeapArr[tempIndex / 2] > data){
        swap(minHeapArr[tempIndex], minHeapArr[tempIndex / 2]);
        tempIndex = tempIndex / 2;
    }
}

void minHeap_pop(){
    if(minHeapIndex == 0){
        cout << 0 << '\n';
        return;
    }
    cout << minHeapArr[1] << '\n';
    minHeapArr[1] = minHeapArr[minHeapIndex--];
    int parent = 1, child;
    while(1){
        child = parent * 2;
        if((child + 1 <= minHeapIndex) && (minHeapArr[child + 1] < minHeapArr[child]))  child++;
        if((child > minHeapIndex) || (minHeapArr[parent] < minHeapArr[child])) break;
        swap(minHeapArr[parent], minHeapArr[child]);
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
        if(temp == 0)   minHeap_pop();
        else    minHeap_push(temp);
    }
	return 0;
}