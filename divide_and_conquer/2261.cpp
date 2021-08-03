#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> pi;

int distance(pi num1, pi num2){
	return pow(num1.first - num2.first, 2) + pow(num1.second - num2.second, 2);
}

pi arr[100000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int x, y;
		cin >> x >> y;
		arr[i].first = x;
		arr[i].second = y;
	}
	return 0;
}