#include <iostream>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque <int> dq;
	int input, numCount;
	int selectedNum [50];
	cin >> input >> numCount;
	for(int i = 1 ; i < input + 1; i++){
		dq.push_back(i);
	}
	int count = 0;
	for(int i = 0; i < numCount; i++){
		int numToFind;
		cin >> numToFind;
		int index = 0;
		for(int i = 0 ; i < dq.size(); i++){
			if(numToFind == dq[i])
				index = i;
		}
		while(true){
			if(numToFind == dq.front()){
				dq.pop_front();
				break;
			}
			else{
				if(index > dq.size() - index){
					int temp = dq.back();
					dq.pop_back();
					dq.push_front(temp);
					count++;
				}
				else{
					int temp = dq.front();
					dq.pop_front();
					dq.push_back(temp);
					count++;
				}
			}
		}
		
		
	}
	cout << count << '\n';

	
	return 0;
}