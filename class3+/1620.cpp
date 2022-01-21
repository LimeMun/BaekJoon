#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, findedNum;
string pocketMonArr[100001];
vector < pair <string, int> > pocketMon;
string findString;

void input(){
    cin >> N >> M;
    for(int i = 1 ; i < N + 1; i++) {
        string temp;
        cin >> temp;
        pocketMonArr[i] = temp;
        pocketMon.push_back(make_pair(temp, i));
    }
}

void binarySearch(int front, int end){
    if(front > end) return;
    int mid = (front + end) / 2;
    if(findString < pocketMon[mid].first ){
        binarySearch(0, mid - 1);
        return;
    }
    else if(findString > pocketMon[mid].first){
        binarySearch(mid + 1, end);
        return;
    }
    else{
        cout << pocketMon[mid].second << '\n';
        return;
    }
}

void answer(){
    for(int i = 0 ; i < M; i++){
        cin >> findString;
        if(findString[0] < 58){ //숫자인경우 숫자로 변환해주기
            int findNum = stoi(findString); 
            cout << pocketMonArr[findNum] << '\n';
            continue;
        }
        else{   //포켓몬 이름인 경우
            binarySearch(0, N - 1);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    input();
    sort(pocketMon.begin(), pocketMon.end());
    answer();
	return 0;
}