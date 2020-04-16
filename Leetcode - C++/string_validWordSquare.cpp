#include <iostream>
#include <vector>

using namespace std; 

bool validWordSquare(vector<string>& words) {
    for(int i = 0; i < words.size(); ++i) {
        for(int j = 0; j < words[i].size(); ++j)             {
            if(j >= words.size() || words[j].size() <= i || words[j][i] != words[i][j])
               return false;
        }
    }
    return true;
}

int main() {
	vector<string> words = {"abcd",
  							"bnrt",
  							"crmy",
  							"dtye"
  						   };

  	if(validWordSquare(words))
  		cout << "Valid Word Square" << endl;
  	else cout << "Invalid Word Square" << endl;
}