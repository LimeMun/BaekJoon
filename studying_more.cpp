#include <iostream>
using namespace std;
void shootingStar(int y, int x, int num){
	if((((y / num) % 3) == 1) && (((x / num) % 3 == 1)))
		cout << ' ';
	else{
		if (num / 3 == 0)
			cout << '*';
		else
			shootingStar(y,x,num/3);
	}
	
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int num;
	cin >> num;
	for(int y = 0 ; y < num ; y++){
		for(int x = 0 ; x < num ; x++){
			shootingStar(y, x, num);
		}
		cout << '\n';
	}
	
	return 0;
}