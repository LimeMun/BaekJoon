#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int ansArr [1000000];
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int input;
// 	배열을 받는 arr
	vector <int> numArr;
// 	비교했을 때 작은 경우 넣는 stacl
	stack <pair<int,int>> temp;
	cin >> input;
	for(int i = 0 ; i < input; i++){
		int temp;
		cin >> temp;
		numArr.push_back(temp);
	}
// 	i-2까지의 원소를 탐색하면서, 다음 원소가 자기보다 작은 경우, index와 값을 push, 큰경우에는 스택의 값을 비교해서 ansArr에 추가하고 pop
	for(int i = 0 ; i < input - 1; i++){
		if(numArr[i+1] <= numArr[i]){
			temp.push(make_pair(i, numArr[i]));
		}
		else{
			ansArr[i] = numArr[i+1];
			while(true){
				if(!temp.empty() && temp.top().second < numArr[i+1]){
					ansArr[temp.top().first] = numArr[i+1];
					temp.pop();
					continue;
				}			
				else break;
			}
		}
	}
// 	나머지 stack에 있는 값들은 모두 자신보다 큰 값이 없는 것이므로 전부 -1
	while(!temp.empty()){
		ansArr[temp.top().first] = -1;
		temp.pop();
	}
// 	마지막 원소는 비교할 대상이 없으니  -1
	ansArr[input -1] = -1;
// 	출력
	for(int i = 0 ; i < input; i++){
		cout << ansArr[i] << '\n';
	}
	return 0;
}