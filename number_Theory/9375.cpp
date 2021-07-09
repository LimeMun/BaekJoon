#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	테스트 케이스 개수
	int input;
	cin >> input;
	for(int i = 0; i < input; i++){
// 		해빈이가 가진 의상의 수
		int secInput;
// 		의상종류를 저장하는 벡터
		vector <string> clothCategoryVector;
// 		의상 종류별로개수를 저장하는 배열
		int clothCount [30] = {0, };
		cin >> secInput;
// 		옷의 이름과 종류 받기.
		for(int j = 0 ; j < secInput; j++){
			// 새로운 종류의 옷인지 판단하는 값
			bool newCloth = true;
			string clothName;
			string clothCategory;
			cin >> clothName >> clothCategory;
			for(int k = 0 ; k < clothCategoryVector.size(); k++){

				if(clothCategoryVector[k] == clothCategory){
					clothCount[k]++;
					newCloth = false;
					break;
				}
			}
			if(newCloth){
				clothCategoryVector.push_back(clothCategory);
				clothCount[clothCategoryVector.size()-1]++;
			}
		}

		
		int finalValue = 1;
		for(int j = 0 ; j < 30; j++){
			if(clothCount[j] == 0)
				break;
			finalValue = finalValue * (clothCount[j] + 1);
		}
		cout << finalValue -1 << '\n';
		
	}
	
	
	return 0;
}
	