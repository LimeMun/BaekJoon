#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <char> charVector;
	int input;
	int index = 1;
	stack <int> my;
	cin >> input;
	for(int i = 0 ; i < input ; i++){
		int temp;
		cin >> temp;

		for(index; index < temp + 1; index++){
			my.push(index);
			charVector.push_back('+');
		}
		
		if(!my.empty() && my.top() == temp){
			charVector.push_back('-');
			my.pop();
		}
		else{
			cout << "NO" << '\n';
			return 0;		
		}
	}
	for(int i = 0 ; i < charVector.size(); i++)
		cout << charVector[i] << '\n';
	return 0;
}