#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	입력 받기
	int input;
	vector <int> divisor;
	cin >> input;
	for(int i = 0; i < input; i++){
		int temp;
		cin >>temp;
		divisor.push_back(temp);
	}
	sort(divisor.begin(), divisor.end());
	cout << divisor[0] * divisor[divisor.size()-1] << '\n';



	return 0;
}