#include <iostream>
#include <string>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int pnum, stringNum;
    string input;
    cin >> pnum >> stringNum;
    cin >> input;
    int ans = 0;
    for(int i = 0 ; i < stringNum; i++){ 
        int k = 0;
        if (input[i] == 'O'){
            continue;
        }
        else{
            while(input[i + 1] == 'O' && input[i + 2] == 'I'){
                k++;
                if(k == pnum){
                    k--;
                    ans++;
                }
                i = i + 2;
            }
        }
    }
    cout << ans << '\n';


	return 0;
}