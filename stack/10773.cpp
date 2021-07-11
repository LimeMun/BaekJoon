#include <iostream>
#include <string>
using namespace std;

class Stack{
	public:

		void push(int num);
		int pop();
		int size();
		bool empty();
		int top();
		int print(int num);
	private:
		int arr[100000] = {0, };
		int index = 0;
};

void Stack::push(int num){
	arr[index] = num;
	index++;
}

int Stack::pop(){
	if(index == 0){
		return -1;
	}
	index--;
	return arr[index];
}

int Stack::size(){
	return index;
}

bool Stack::empty(){
	if(index == 0)
		return true;
	return false;
}

int Stack::top(){
	if(index == 0)
		return -1;
	return arr[index - 1];
}
int Stack::print(int num){
	return arr[num];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Stack stack;
	int input;
	cin >> input;
	for(int i = 0 ; i < input; i++){
		int num;
		cin >> num;
		if(num == 0)
			stack.pop();
		else
			stack.push(num);
	}
	int sum = 0;
	for(int i = 0 ; i < stack.size(); i++){
		sum += stack.print(i);
	}
	cout << sum << '\n';
	return 0;
}