#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, string> memo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N , M;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string site, passwd;
        cin >> site >> passwd;
        memo.insert(make_pair(site, passwd));
    }
    for(int i = 0 ; i < M; i++){
        string toFindSite;
        cin >> toFindSite;
        cout << memo.find(toFindSite)->second << '\n'; // find 함수는 iter를 반환하므로, ->로 접근해준다.
    }

	return 0;
}