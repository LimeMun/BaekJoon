#include <iostream>
#include <string>
using namespace std;

bool checkTrue(string inputString){
	int firstCount = 0;
	int secondCount = 0;
	for(int i = 0 ; i < inputString.size(); i++){
		if(inputString[i] == '(')
			firstCount++;
		else
			secondCount++;
		if(secondCount > firstCount)
			return false;
	}
	if(firstCount != secondCount)
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	for(int i = 0; i < input; i++){
		string inputString;
		cin >> inputString;
		if(checkTrue(inputString))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	
	return 0;
}