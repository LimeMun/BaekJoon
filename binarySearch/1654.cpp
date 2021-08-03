#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long arr[10000];
int K, N;
int makeLanCable(long long start, long long end){
	long long mid = (start + end) / 2;
	long long cableCount = 0;
	for(int i = 0 ; i < K; i++){
		cableCount += arr[i] / mid;
	}
	return cableCount;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> K >> N;
	for(int i = 0; i < K; i++){
		cin >> arr[i]; 
	}
	sort(arr, arr + K);
	int ansLength = 0;
	long long start = 1;
	long long end = arr[K - 1];
	
	while(true){
		if(start > end)
			break;
		long long temp = makeLanCable(start, end);
		long long mid = (start + end) / 2;

		if(temp < N){
			end =  mid - 1;
		}
		else{
			if(ansLength < mid)
				ansLength = mid;
			start = mid + 1;
		}
	}
	cout << ansLength << '\n';
	
	
	
	return 0;
}