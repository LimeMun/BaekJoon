#include <iostream>
#include <string>
using namespace std;
int bitmask = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    while(num-- > 0){
        string inputString;
        cin >> inputString;
        if(inputString == "add"){
            int inputNum;
            cin >> inputNum;
            int bitNum = 1 << inputNum;
            if( bitNum != (bitmask & bitNum)){   // 그 숫자가 존재하지 않는다면,
                bitmask += bitNum;
            }
            continue;
        }
        else if(inputString == "remove"){
            int inputNum;
            cin >> inputNum;
            int bitNum = 1 << inputNum;
            if( bitNum == (bitmask & bitNum)){   // 그 숫자가 존재한다면,
                bitmask -= bitNum;
            }
            continue;
        }
        else if(inputString == "check"){
            int inputNum;
            cin >> inputNum;
            int bitNum = 1 << inputNum;
            if( bitNum == (bitmask & bitNum)){   // 그 숫자가 존재한다면,
                cout << 1 << '\n';
            }
            else    cout << 0 << '\n';
            continue;

        }
        else if(inputString == "toggle"){
            int inputNum;
            cin >> inputNum;
            int bitNum = 1 << inputNum;
            if( bitNum == (bitmask & bitNum)){   // 그 숫자가 존재한다면,
                bitmask -= bitNum; // 그 숫자를 제거
            }
            else    bitmask += bitNum;
            continue;

        }
        else if(inputString == "all"){
            bitmask = 0;
            for(int i = 1; i < 21; i++){
                int bitNum = (1 << i);
                bitmask += bitNum;
            }
            continue;

        }
        else if(inputString == "empty"){
            bitmask = 0;
        }
    }
	return 0;
}