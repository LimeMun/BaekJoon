#include <iostream>
#include <string>
using namespace std;

struct Node{
	
	int data;
	Node * next, * prev;
	Node(){
		next = prev = NULL;
		data = 0;
	}
	Node(int num, Node * ptr){ // ptr 뒤에 추가한다.
		data = num;
		prev = ptr;
		next = ptr -> next;
		next -> prev = prev -> next = this;
	}
	void deleteNode(){
		prev -> next = next;
		next -> prev = prev;
		delete this;
	}
};

struct DLinkedList{
	Node * head;
	Node * tail;
	int count;
	DLinkedList(){ //링크드리스트 초기화.
		count = 0;
		head = new Node();
		tail = new Node();
		head -> next = tail;
		tail -> prev = head;
	}
	void push_front(int num){
		new Node(num, head);
		count++;
	}
	void push_back(int num){
		new Node(num, tail -> prev);
		count++;
	}
	int pop_front(){
		if(count == 0)
			return -1;
		int temp = head -> next -> data;
		head -> next -> deleteNode();
		count--;
		return temp;
	}
	int pop_back(){
		if(count == 0)
			return -1;
		int temp = tail -> prev -> data;
		tail -> prev -> deleteNode();
		count--;
		return temp;
	}
	int size(){
		return count;
	}
	bool empty(){
		if(count == 0)
			return true;
		return false;
	}
	int print_front(){
		if(count == 0)
			return -1;
		return head -> next -> data;
	}
	int print_back(){
		if(count == 0)
			return -1;
		return tail -> prev -> data;
	}	
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	DLinkedList * list = new DLinkedList();
	int input;
	cin >> input;
	for(int i = 0 ; i < input; i++){
		string inputString;
		cin >> inputString;
		if(inputString == "push_front"){
			int num;
			cin >> num;
			list -> push_front(num);
		}
		else if(inputString == "push_back"){
			int num;
			cin >> num;	
			list -> push_back(num);
		}
		else if(inputString == "pop_front")	cout << list -> pop_front() << '\n';
		else if(inputString == "pop_back")	cout << list -> pop_back() << '\n';
		else if(inputString == "size")	cout << list -> size() << '\n';
		else if(inputString == "empty")	cout << list -> empty() << '\n';
		else if(inputString == "front")	cout << list -> print_front() << '\n';
		else if(inputString == "back")	cout << list -> print_back() << '\n';
	}
	

	return 0;
}