#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	int num;
	cin >> input;
	vector <int> numArr;
	vector <int> copyNumArr;
	for(int i = 0 ; i < input; i++){
		cin >> num;
		numArr.push_back(num);
		copyNumArr.push_back(num);
	}
	sort(copyNumArr.begin(), copyNumArr.end());
// 	unique함수는 벡터에서 중복되는 값을 벡터의 제일 뒤의 쓰레기 값으로 넣어버린다.
//	unqiue함수의 리턴값을 쓰레기 값이 시작되는 곳의 iterator 값이다.
	copyNumArr.erase(unique(copyNumArr.begin(), copyNumArr.end()), copyNumArr.end());
// 	lower_bound 함수는 특정 수 이하의 값이 나타나는 최대의 정수를 나타내준다.
// 	그리고 lower_bound함수를 쓴 후 int 형으로 바꿔주기 위해서, .begin()를 이용해서 반복자끼리의 연산을 했다.
// 	iterator는 출력이 불가하다!! iterator은 그것 자체로 값을 갖고있지 않기 때문이다. 그래서 .begin()함수와 같은 연산을 통해서 출력해내야한다.
	for(int i = 0 ; i < input; i++){
		int answer = lower_bound(copyNumArr.begin(), copyNumArr.end(), numArr[i]) - copyNumArr.begin();
		cout << answer << '\n';
	}
	
	
	return 0;
}