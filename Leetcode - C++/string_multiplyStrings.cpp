#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	int i, j;
	int m = num1.size(), n = num2.size();
	vector<int> product(m+n, 0);
	string res; 

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			product[i+j] += (num1[i] - '0') * (num2[j] - '0');
			product[i+j+1] += product[i+j] / 10;
			product[i+j] %= 10; 
		}
	}

    for (i = m + n - 1; i > 0 && 0 == product[i]; i--)
        ;
    
    for (; i >= 0; i--)
        result += to_string(product[i]);

    return result;
}

int main() {
	string num1 = "6";
	string num2 = "5";
	string res = multiply(num1, num2);
	cout << "Result : " << res << endl;
}