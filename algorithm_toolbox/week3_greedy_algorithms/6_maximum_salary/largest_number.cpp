#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int IsGreater(string str1, string str2) {
	if (str1.length() == 0)
		return -1;
	if (str2.length() == 0)
		return 0;

	//logic for equal lengths
	if (str2.length() == str1.length())
		return (str1 > str2);
	
	//logic for unequal lengths
	
	return (str1.append(str2) > str2.append(str1));
}

string largest_number(vector<string> a) {

	//write your code here
	std::stringstream ret;
	string maxDigit;
	int maxDigit_index;
	while (a.size() > 0) {
		maxDigit = ' ';
		//std::cout << maxDigit;
		for (size_t i = 0; i < a.size(); i++) {
			if (IsGreater(a[i], maxDigit)) {
				maxDigit = a[i];
				maxDigit_index = i;
			}
		}
		ret << maxDigit;
		a.erase(a.begin()+maxDigit_index);
	}

	
	string result;
	ret >> result;
	return result;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
}
