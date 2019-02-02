#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cout;
using std::cin;
using std::endl;

//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
	//write your code here
	vector<int> digits;
	vector<char> operations;
	bool flag = 1;

	//get string into vector of digits and operations
	for (size_t i = 0; i < exp.size();i++) {
		if (flag == 1) {
			flag = 0;
			digits.push_back(exp[i]-'0');
		} else {
			flag = 1;
			operations.push_back(exp[i]);
		}
	}
	/*for (size_t i = 0; i < digits.size(); i++)
		PRINT_VERBOSE(<< digits[i] << " ");
	for (size_t i = 0; i < operations.size(); i++)
		PRINT_VERBOSE(<< operations[i] << " ");

*/
	//algo starts
	vector<vector<long long>> MAX_VALUES(digits.size());
	for (size_t i = 0; i < digits.size(); i++) {
		MAX_VALUES[i] = vector<long long>(digits.size(), 0);
	}

	vector<vector<long long>> MIN_VALUES(digits.size());
	for (size_t i = 0; i < digits.size(); i++) {
		MIN_VALUES[i] = vector<long long>(digits.size(), 0);
	}

	for (size_t i = 0; i < digits.size(); i++) {
		MIN_VALUES[i][i] = digits[i];
		MAX_VALUES[i][i] = digits[i];
	}
	long long j = 0;
	long long a = 0;
	long long b = 0;
	long long c = 0;
	long long d = 0;
	long long max_value = std::numeric_limits<long long>::min();
	long long min_value = std::numeric_limits<long long>::max();
	for (size_t difference = 1; difference < digits.size(); difference++) {
		for (size_t i = 0; i < digits.size() - difference; i++) {
			j = i + difference;
			PRINT_VERBOSE(<< "i:" << i << "j: " << j << "difference:" << difference << endl);
			min_value = std::numeric_limits<long long>::max();
			max_value = std::numeric_limits<long long>::min();
			for (size_t k = i; k < j; k++) {
				PRINT_VERBOSE(<< "k:" << k << endl);
				a = eval(MAX_VALUES[i][k], MAX_VALUES[k + 1][j], operations[k]);
				b = eval(MAX_VALUES[i][k], MIN_VALUES[k + 1][j], operations[k]);
				c = eval(MIN_VALUES[i][k], MIN_VALUES[k + 1][j], operations[k]);
				d = eval(MIN_VALUES[i][k], MAX_VALUES[k + 1][j], operations[k]);
				min_value = min(min_value, min(a, min(b, min(c, d))));
				max_value = max(max_value, max(a, max(b, max(c, d))));
				PRINT_VERBOSE(<< a << " " << b << " " << c << " " << d <<" " << endl);
			}
			MIN_VALUES[i][j] = min_value;
			MAX_VALUES[i][j] = max_value;
		}
	}
	PRINT_VERBOSE(<< endl); PRINT_VERBOSE(<< endl);
	for (size_t i = 0; i < digits.size(); i++) {
		for (size_t j = 0; j < digits.size(); j++)
			PRINT_VERBOSE(<< MIN_VALUES[i][j] << " ");
		PRINT_VERBOSE(<< endl);
	}
	PRINT_VERBOSE(<< endl); PRINT_VERBOSE(<< endl);
	for (size_t i = 0; i < digits.size(); i++) {
		for (size_t j = 0; j < digits.size(); j++)
			PRINT_VERBOSE(<< MAX_VALUES[i][j] << " ");
		PRINT_VERBOSE(<< endl);
	}
	return MAX_VALUES[0][digits.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
