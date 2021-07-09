#include <iostream>
#include <vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
// 	변수 initialization
	int input;
	int temp;
	vector <unsigned long long > distance;
	vector <int> oilPrice;
// 	입력 받기
	cin >> input;
	for(int i = 0 ; i < input - 1; i++){
		cin >> temp;
		distance.push_back(temp);
	}
	for(int i = 0 ; i< input; i++){
		cin >> temp;
		oilPrice.push_back(temp);
	}
	
	unsigned long long minOilPrice = oilPrice[0];
	unsigned long long sum = 0;
	for(int i = 0; i < distance.size(); i++){
		unsigned long long temp2 = minOilPrice * distance[i];
		sum = sum + temp2;
		if(oilPrice[i+1] < minOilPrice)
			minOilPrice = oilPrice[i+1];
	}
	
	cout << sum << '\n';
	return 0;
}